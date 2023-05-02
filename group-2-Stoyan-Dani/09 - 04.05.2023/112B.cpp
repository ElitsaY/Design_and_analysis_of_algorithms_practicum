#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, m, t, a, b, q, par[MAX], depth[MAX];

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
	}
	else
	{
		par[a] = b;
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
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		uni(a, b);
	}
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> t >> a >> b;
		if(t == 1)
		{
			cout << (find(a) == find(b));
		}
		else
		{
			uni(a, b);
		}
	}
	
	cout << endl;
	return 0;
}

/*

9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
6
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7

*/
