#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

#define PA pair<int, int>

long long n, m, k, a, b, p, t;

struct neighbour
{
	long long b, p, t;
	neighbour(int _b, int _p, int _t) : b{_b}, p{_p}, t{_t}
	{
	}
};

bool used[MAX];

long long dist[MAX];

vector<neighbour> graph[MAX];

long long dijkstra(int from, int to, int edge_restriction)
{
	int node;
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	pq.push({0, from});
	dist[from] = 0;
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node])continue;
		used[node] = true;
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(graph[node][i].p <= edge_restriction && dist[graph[node][i].b] > dist[node] + graph[node][i].t)
			{
				dist[graph[node][i].b] = dist[node] + graph[node][i].t;
				pq.push({dist[graph[node][i].b], graph[node][i].b});
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
	cin >> n >> m >> k;

	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> p >> t;
		graph[a].push_back({b, p, t});
	}

	int l = 0, r = INT_MAX / 3, mid, opt = -1;
	while(l <= r)
	{
		mid = (l + r) / 2;

		fill(dist, dist + n + 2, LLONG_MAX / 123);
	    fill(used, used + n + 2, false);
		if(dijkstra(1, n, mid) <= k)
		{
			opt = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	cout << opt << endl;
	return 0;
}
