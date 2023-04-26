#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

#define PA pair<int, int>

int n, m, k, a, b, c, d, used[MAX], dist[MAX], node;

vector<PA> gr[MAX];

priority_queue<PA, vector<PA>, greater<PA> > q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}

	fill(dist, dist + n + 2, INT_MAX / 4);

	dist[1] = 0;
	q.push({0, 1});
	while(!q.empty())
	{
		node = q.top().second;
		d = q.top().first;
		q.pop();
		if(used[node] == k)continue;
		used[node]++;
		dist[node] = d;
		if(node == n)cout << d << " ";
		for(int i = 0; i < gr[node].size(); i++)
		{
			if(used[gr[node][i].first] < k)q.push({dist[node] + gr[node][i].second, gr[node][i].first});
		}
	}

	cout << endl;
	return 0;
}
