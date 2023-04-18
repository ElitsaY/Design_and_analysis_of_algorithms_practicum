#include <bits/stdc++.h>

using namespace std;

#define MAX 512

int n, m, a, b, ans;

bool used[MAX];

vector<int> gr[MAX];

void dfs(int node)
{
	used[node] = true;
	for(int i = 0; i < gr[node].size(); i++)
	{
		if(!used[gr[node][i]])dfs(gr[node][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			ans++;
			dfs(i);
		}
	}
	
	cout << ans << endl;
	return 0;
}
