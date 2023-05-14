#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int n, m, par[MAX], depth[MAX];

struct edge
{
	int a, b, c;
	
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
	
}edges[MAX];

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
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
	else if(depth[a] < depth[b])
	{
		par[a] = b;
	}
	else if(depth[a] == depth[b])
	{
		par[a] = b;
		depth[b]++;
	}
}

void Kruskal()
{
	sort(edges, edges + m);
	for(int i = 0; i < m; i++)
	{
		if(find(edges[i].a) == find(edges[i].b))continue;
		
		uni(edges[i].a, edges[i].b);
		cout << edges[i].a << " " << edges[i].b << " " << edges[i].c << endl;
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0; i < m; i++)cin >> edges[i].a >> edges[i].b >> edges[i].c;
	
	Kruskal();
	
	return 0;
}

/*

9 13
7 8 1
3 9 2
2 3 8
1 2 4
4 6 14
3 6 4
9 7 6
7 6 2
8 9 7
5 6 10
3 4 7
1 8 8
4 5 9
---------------------
7 8 1
3 9 2
7 6 2
1 2 4
3 6 4
3 4 7
2 3 8
4 5 9

*/
