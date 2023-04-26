#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

#define PA pair<int, int>

int n, m, k[MAX], par[MAX], a, b, c;

vector<PA> graph[MAX];

bool used[MAX];

int dist[MAX];

int dijkstra(int from, int to)
{

	int node = from;
	fill(dist, dist + n + 2, INT_MAX / 2);
	dist[node] = 0;
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	pq.push({0, node});
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;

		used[node] = true;
		for(int i = 0; i < graph[node].size(); i++)
		{
			int new_dist = dist[node] + graph[node][i].second;
			if(graph[node][i].first != to)
                new_dist = (new_dist / k[graph[node][i].first] + (new_dist % k[graph[node][i].first] != 0)) * k[graph[node][i].first];
			if(dist[graph[node][i].first] > new_dist)
			{
				dist[graph[node][i].first] = new_dist;
                par[graph[node][i].first] = node;
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

	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> k[i];
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
	}

	dijkstra(1, n);
	if(dist[n] == INT_MAX / 2)
	{
		cout << "-1\n";
	}
	else
	{
		cout << dist[n] << endl;
		stack<int> s;
		int node = n;
		while(node != 0)
		{
			s.push(node);
			node = par[node];
		}
		cout << s.size() << endl;
		while(!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}

	return 0;
}
