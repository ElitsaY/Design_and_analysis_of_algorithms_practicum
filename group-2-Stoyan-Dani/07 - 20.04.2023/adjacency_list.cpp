#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, a, b, c, v;

vector< int > graph[MAX];

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
		for(int i = 0; i < graph[node].size(); i++)
		{
			if(used[graph[node][i]] == false)
			{
				used[graph[node][i]] = true;
				q.push(graph[node][i]);
			}
		}
	}
	
	return ;
}

void dfs(int node)
{
	used[node] = true;
	for(int i = 0; i < graph[node].size(); i++)
	{
		if(used[graph[node][i]] == false)dfs(graph[node][i]);
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
	for(int i = 0; i < graph[v].size(); i++)
	{
		cout << graph[v][i] << " ";
	}	
	cout << endl;
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	
	cout << components() << endl;
	return 0;
}

/*

17 18
1 2
1 11
3 4
3 11
3 6
3 7
3 5
5 8
5 9
5 10
6 7
7 8
7 12
7 13
13 14
15 16
15 17
16 17

*/
