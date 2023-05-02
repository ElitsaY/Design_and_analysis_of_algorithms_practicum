#include <bits/stdc++.h>

using namespace std;

#define MAX 1011

int n, m, par[MAX], child[MAX], depth[MAX], ans = INT_MAX / 2, optl, optr;

struct edge
{
	int a, b, c;
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
}edges[10110];

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
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
	}
	sort(edges, edges + m);
	
	for(int l = 0; l < m; l++)
	{
		fill(depth + 1, depth + n + 1, 1);
		fill(child + 1, child + n + 1, 1);
		fill(par + 1, par + n + 1, 0);
		for(int r = l; r < m; r++)
		{
			uni(edges[r].a, edges[r].b);
			if(child[find(edges[r].a)] == n)
			{
				if(ans > edges[r].c - edges[l].c)
				{
					ans = edges[r].c - edges[l].c;
					optl = edges[l].c;
					optr = edges[r].c;
				}
				break;
			}
		}
	}
	cout << optl << " " << optr << endl;
	return 0;
}

/*

7 10 
1 3 2
4 2 8
1 2 11
1 4 3
1 3 6
5 3 5
3 6 9
7 6 6
5 6 3
2 5 7


*/
