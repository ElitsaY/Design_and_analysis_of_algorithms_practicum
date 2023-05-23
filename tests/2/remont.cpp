#include <bits/stdc++.h>

using namespace std;

#define MAX 1100

int n, m, par[MAX], depth[MAX], k[MAX], ans;

vector<pair<int, int> > pairs;

struct edge
{
	int a, b, c;
	
	bool operator<(const edge& other)
	{
		return c < other.c;
	}
	
}edges[100 * MAX];

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
	return;
}

void Kruskal()
{
	int cnt = 0;
	sort(edges, edges + m);
	for(int i = 0; i < m, cnt < n - 1; i++)
	{
		if(find(edges[i].a) == find(edges[i].b))continue;
		
		uni(edges[i].a, edges[i].b);
		ans += edges[i].c;
		pairs.push_back({edges[i].a, edges[i].b});
		cnt++;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> k[i];
	for(int i = 0; i < m; i++)
	{
		cin >> edges[i].a >> edges[i].b >> edges[i].c;
		edges[i].c = k[edges[i].a] * (edges[i].c / 2 + (edges[i].c) % 2) + k[edges[i].b] * (edges[i].c / 2);
	
	}
	
	Kruskal();
	
	cout << ans << endl;
	sort(pairs.begin(), pairs.end());
	for(int i = 0; i < n - 1; i++)cout << pairs[i].first << " " << pairs[i].second << endl;
	
	
	return 0;
}

/*


*/
