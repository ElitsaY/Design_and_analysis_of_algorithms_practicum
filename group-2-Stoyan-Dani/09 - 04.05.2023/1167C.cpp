#include <bits/stdc++.h>

using namespace std;

#define MAX 510000

int n, m, par[MAX], depth[MAX], child[MAX], last, k, a;

int find(int v)
{
	if(par[v] == 0)return v;
	return par[v] = find(par[v]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b)return;
	if(depth[a] > depth[b])
	{
		par[b] = a;
		child[a] += child[b];
	}
	else
	{
		par[a] = b;
		child[b] += child[a];
		if(depth[a] == depth[b])depth[b]++;
	}
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	fill(child + 1, child + n + 1, 1);
	
	for(int i = 0; i < m; i++)
	{
		cin >> k;
		last = -1;
		for(int j = 0; j < k; j++)
		{
			cin >> a;
			if(last == -1)last = a;
			uni(a, last);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << child[find(i)] << " ";
	}
	cout << endl;
	return 0;
}
