#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

#define PA pair<int, int>

int n, m, a, b, p, q, dist[MAX];

vector<PA> graph[MAX];

bool used[MAX];

int dijkstra(int from, int to)
{
	int node;
	fill(dist, dist + n + 2, INT_MAX / 2);
	dist[from] = 0;
	priority_queue<PA, vector<PA>, greater<PA> > pq;
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
				dist[graph[node][i].first] = dist[node] + graph[node][i].second;
				pq.push({dist[graph[node][i].first], graph[node][i].first});
			}
		}
	}
	return dist[to];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> p >> q;

	while(cin >> a >> b)
	{
		graph[a].push_back({b, 0});
		graph[b].push_back({a, 1});
	}

	dijkstra(p, q);
	if(dist[q] == INT_MAX / 2)cout << "X\n";
	else cout << dist[q] << endl;

	return 0;
}
