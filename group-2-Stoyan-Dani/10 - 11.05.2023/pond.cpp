#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

long long n, m, s, f, a, b, c, t, dist[MAX][2], par[MAX][2], cnt;

struct adj_el
{
	long long b, c, t;
};

vector<adj_el> gr[MAX];

bool used[MAX][2];

#define PA pair<long long, int>

void dijkstra(int node, int idx)
{
	priority_queue<PA, vector<PA>, greater<PA> > pq;
	pq.push({0, node});
	for(int i = 1; i <= n; i++)dist[i][idx] = LLONG_MAX / 3;
	dist[node][idx] = 0;
	while(!pq.empty())
	{
		node = pq.top().second;
		pq.pop();
		if(used[node][idx])continue;
		used[node][idx] = true;
		for(int i = 0; i < gr[node].size(); i++)
		{
			if(used[gr[node][i].b][idx] == false && gr[node][i].t - idx <= 1 && dist[gr[node][i].b][idx] > dist[node][idx] + gr[node][i].c * (idx + 1))
			{
				dist[gr[node][i].b][idx] = dist[node][idx] + gr[node][i].c * (idx + 1);
				pq.push({dist[gr[node][i].b][idx], gr[node][i].b});
				par[gr[node][i].b][idx] = node;
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> t;
		gr[a].push_back({b, c, t});
		gr[b].push_back({a, c, t});
	}
	
	cin >> s >> f;
	
	dijkstra(s, 0);
	dijkstra(s, 1);
	
	if(dist[f][1] > dist[f][0])
	{
		cout << "Rabbit" << endl;
	}
	else if(dist[f][1] < dist[f][0])
	{
		cout << "Tortoise" << endl;
	}
	else cout << "Tie" << endl;
	
	cout << min(dist[f][1], dist[f][0]) << endl;
	
	int u = f, v = f;
	
	while(u != s && v != s)
	{
		if(u == v && dist[u][0] == dist[v][1])
		{
			if(u != s && u != f)cnt++;
			u = par[u][0];
			v = par[v][1];
		}
		else if(dist[u][0] > dist[v][1])
		{
			u = par[u][0];
		}
		else if(dist[u][0] < dist[v][1])
		{
			v = par[v][1];
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
