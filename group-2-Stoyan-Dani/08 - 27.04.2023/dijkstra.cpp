#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, a, b, c, v;

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
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	
	
	dijkstra(1);
	for(int i = 1; i <= n; i++)
	{
		cout << i << " " << dist[i] << endl;
	}
	return 0;
}

/*

7 10
1 6 2
1 3 3
3 6 2
3 5 1
3 4 4
4 2 1
2 7 2
6 2 6
5 2 2
6 7 5
5 6 3


*/
