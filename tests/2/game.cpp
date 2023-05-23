#include <bits/stdc++.h>

using namespace std;

#define MAX 30010

int n, m, a, b, c, d, v, k;

vector<pair<int, int> > graph[MAX];

bool used[MAX];

int dist[MAX], par[MAX];

#define PA pair<int, int> 

void dijkstra(int from)
{
	int node;
	fill(dist, dist + n + 2, INT_MAX / 2);
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	dist[from] = 0;
	pq.push({0, from});
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(dist[graph[node][i].first] > dist[node] + graph[node][i].second)
			{
				par[graph[node][i].first] = node;
				dist[graph[node][i].first] = dist[node] + graph[node][i].second;
				pq.push({dist[graph[node][i].first], graph[node][i].first});
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> d;
		graph[a].push_back({b, d - c});
		graph[b].push_back({a, d - c});
	}
	
	
	dijkstra(1);
	cout << k - dist[n] << endl;
	return 0;
}

/*


*/
