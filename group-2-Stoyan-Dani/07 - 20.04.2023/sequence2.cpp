#include <bits/stdc++.h>

using namespace std;

#define MOD 1000007

int a, b, node, dist[MOD], adj1, adj2;

queue<int> q;

int reverse(int x)
{
	int res = 0;
	while(x != 0)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	cin >> a >> b;
	q.push(a);
	fill(dist, dist + MOD, -1);
	dist[a] = 1;
	while(q.front() != b)
	{
		node = q.front();
		q.pop();
		adj1 = (node + 1) % MOD;
		adj2 = (reverse(node)) % MOD;
		if(dist[adj1] == -1)
		{
			dist[adj1] = dist[node] + 1;
			q.push(adj1);
		}
		if(dist[adj2] == -1)
		{
			dist[adj2] = dist[node] + 1;
			q.push(adj2);
		}
	}
	cout << dist[b] << endl;
	return 0;
}
