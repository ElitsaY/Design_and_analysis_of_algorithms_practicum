#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

#define PA pair<int, int>

int n, m, par[MAX], a, b, c;

vector<PA> graph[MAX];

bool used[MAX];

long long dist[MAX];

long long dijkstra(int from, int to)
{

	int node = from;
	fill(dist, dist + n + 2, LLONG_MAX / 2);
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

			if(dist[graph[node][i].first] > dist[node] + graph[node][i].second)
			{
				dist[graph[node][i].first] = dist[node] + graph[node][i].second;
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
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	dijkstra(1, n);
	if(dist[n] == LLONG_MAX / 2)
	{
		cout << "-1\n";
	}
	else
	{
		stack<int> s;
		int node = n;
		while(node != 0)
		{
			s.push(node);
			node = par[node];
		}
		while(!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}

	return 0;
}
