#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, k, a, b, c, ans;

bool used[MAX];

vector<pair<int, int> > gr[MAX];

void dfs(int node)
{
	used[node] = true;
	for(int i = 0; i < gr[node].size(); i++)
	{
		if(!used[gr[node][i].first] && gr[node][i].second >= k)dfs(gr[node][i].first);
	}
	return ;
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
		gr[a].push_back({b, c});
		gr[b].push_back({a, c});
	}
	cin >> k;
	
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			ans++;
			dfs(i);
		}
	}
	
	cout << ans - 1 << endl;
	return 0;
}
