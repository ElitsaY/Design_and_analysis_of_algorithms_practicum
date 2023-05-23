#include <bits/stdc++.h>

using namespace std;

#define MAX 603

bool used[MAX * MAX];

long long n, m, k, ans, a[MAX], b[MAX], dist[MAX * MAX];

char mat[MAX][MAX];

long long encode(long long x, long long y)
{
	return x * m + y;
}

pair<long long, long long> decode(long long v)
{
	return {v / m, v % m};	
}

void bfs()
{
	int node, adj;
	queue<long long> q;
	
	for(int i = 0; i < k; i++)
	{
		node = encode(a[i], b[i]);
		q.push(node);
		dist[node] = 0;
	}
	
	
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		used[node] = true;
		
		
		int i = decode(node).first;
		int j = decode(node).second;
		if(mat[i][j] == '#')continue;
		
		if(i > 0)
		{
			adj = encode(i - 1, j);
			if(!used[adj])
			{
				q.push(adj);
				used[adj] = true;
				dist[adj] = min(dist[adj], dist[node] + 1);
			}
		}
		if(j > 0)
		{
			adj = encode(i, j - 1);
			if(!used[adj])
			{
				q.push(adj);
				used[adj] = true;
				dist[adj] = min(dist[adj], dist[node] + 1);
			}
		}
		if(i + 1 < n)
		{
			adj = encode(i + 1, j);
			if(!used[adj])
			{
				q.push(adj);
				used[adj] = true;
				dist[adj] = min(dist[adj], dist[node] + 1);
			}
		}
		if(j + 1 < m)
		{
			adj = encode(i, j + 1);
			if(!used[adj])
			{
				q.push(adj);
				used[adj] = true;
				dist[adj] = min(dist[adj], dist[node] + 1);
			}
		}
		
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)cin >> mat[i][j];
		
	fill(dist, dist + n * m + 3, LLONG_MAX / 3);
		
		
	for(int i = 0; i < k; i++)
	{
		cin >> a[i] >> b[i];
		a[i]--; 
		b[i]--;
	}
	
	bfs();
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(mat[i][j] != '#')ans += dist[encode(i, j)];
		}
	}
	
	cout << ans << endl;
	return 0;
}

/*

9 3 1
.##
...
##.
...
.##
...
##.
...
.##
1 1

*/
