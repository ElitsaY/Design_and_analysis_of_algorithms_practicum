#include <bits/stdc++.h>

using namespace std;

#define MAX 310000

int t, n, q, a[MAX], b, par[MAX], depth[MAX], color[MAX], repres[MAX], br, w, e, r;

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b, int col)
{
	a = find(a);
	b = find(b);
	if(a == b)return ;
	if(depth[a] > depth[b])
	{
		par[b] = a;
		color[a] = col;
	}
	else
	{
		par[a] = b;
		color[b] = col;
		if(depth[a] == depth[b])depth[b]++;
	}
	return ;
}

void solve(int ts)
{
	cin >> n >> q;
	cout << "Case " << ts << ":" << endl;
	
	fill(depth, depth + MAX, 0);
	fill(par, par + MAX, 0);
	fill(repres, repres + MAX, 0);
	fill(color, color + MAX, 0);
	br = 100001;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(repres[a[i]] == 0)repres[a[i]] = i;
		uni(i, repres[a[i]], a[i]);
		color[i] = a[i];
	}
	
	for(int i = 0; i < q; i++)
	{
		cin >> w;
		if(w == 1)
		{
			cin >> e >> r;
			
			if(repres[e] == 0)continue;
			if(repres[r] == 0)
			{
				repres[r] = br++;
				color[br - 1] = r;
			}
			uni(repres[e], repres[r], r);
			repres[e] = 0;
		}
		else
		{
			cin >> e;
			cout << color[find(e)] << endl;
		}
	}
	
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	
	for(int i = 1; i <= t; i++)solve(i);
	
	return 0;
}

/*

1
5 7
1 1 1 5 5
2 1
1 1 3
2 1
1 5 1
2 1
2 4



1
5 11
1 2 3 4 5
1 1 3
2 1
1 3 5
2 1
1 2 1
2 2
1 5 2
1 2 3
2 1 
2 3
2 5

5 1 5 4 5



*/
