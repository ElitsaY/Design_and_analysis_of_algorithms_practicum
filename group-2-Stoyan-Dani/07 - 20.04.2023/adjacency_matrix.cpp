#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, v, a, b, c;

int mat[MAX][MAX];

bool used[MAX];

void bfs(int node)
{
	queue<int> q;
	q.push(node);
	used[node] = true;
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		cout << node << " ";
		for(int i = 1; i <= n; i++)
		{
			if(mat[node][i] != 0 && used[i] == false)
			{
				used[i] = true;
				q.push(i);
			}
		}
	}
	
	return ;
}

void dfs(int node)
{
	used[node] = true;
	for(int i = 1; i <= n; i++)
	{
		if(mat[node][i] != 0 && used[i] == false)dfs(i);
	}
}

int components()
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(used[i] == false)
		{
			dfs(i);
			ans++;
		}
	}
	return ans;
}

void print_neighbours(int v)
{
	for(int i = 1; i <= n; i++)
	{
		if(mat[v][i] != 0)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
	
	cout << components() << endl;
	return 0;
}

/*



*/
