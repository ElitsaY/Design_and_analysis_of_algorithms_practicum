#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

long long n, m, par[MAX], depth[MAX], ans, cnt;

struct edge
{
	long long a, b, c;
	
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
	
	friend istream& operator>>(istream& in, edge& edge)
	{
		in >> edge.a >> edge.b >> edge.c;
		return in;
	}
}edges[101000];

int find(int a)
{
	if(par[a] == 0)return a;
	return par[a] = find(par[a]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
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
	for(int i = 0; i < m; i++)cin >> edges[i];
	
	sort(edges, edges + m);
	
	for(int i = 0; i < m; i++)
	{
		if(find(edges[i].a) == find(edges[i].b))
		{
			ans += edges[i].c;
			continue;
		}
		uni(edges[i].a, edges[i].b);
		cnt++;
	}
	
	if(cnt != n - 1)cout << "-1" << endl;
	else cout << ans << endl;
	return 0;
}
