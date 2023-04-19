#include <bits/stdc++.h>

using namespace std;

#define MAX 104

int n, m, k, a, b, ans;

bool blocked[MAX][MAX], used[MAX * MAX];

vector<int> gr[MAX * MAX];

int coords_to_int(int x, int y)
{
	return m * x + y;
}

void dfs(int node)
{
	used[node] = true;
	for(int i = 0; i < gr[node].size(); i++)
	{	
		if(!used[gr[node][i]])dfs(gr[node][i]);
	}
}

void build_graph()
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!blocked[i][j])
			{
				if(i + 1 <= n)gr[coords_to_int(i, j)].push_back(coords_to_int(i + 1, j));
				if(j + 1 <= m)gr[coords_to_int(i, j)].push_back(coords_to_int(i, j + 1));
				if(i - 1 >= 1)gr[coords_to_int(i, j)].push_back(coords_to_int(i - 1, j));
				if(j - 1 >= 1)gr[coords_to_int(i, j)].push_back(coords_to_int(i, j - 1));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	cin >> k;
	for(int i = 0; i < k; i++)
	{
		cin >> a >> b;
		blocked[a][b] = true;
	}
	
	build_graph();
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!blocked[i][j] && used[coords_to_int(i, j)] == false)
			{
				dfs(coords_to_int(i, j));
				ans++;
			}
		}
	}
	
	cout << ans << endl;
		
	return 0;
}
