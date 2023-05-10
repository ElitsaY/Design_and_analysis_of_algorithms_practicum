#include <bits/stdc++.h>

using namespace std;

#define MAX 100100

long long n, m, a, b, par[MAX], depth[MAX], cnt = 1;

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
	
	if(n == 1)
	{
		cout << "0" << endl;
		return 0;
	}
	
	for(int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		
		if(find(a) == find(b))continue;
		uni(a, b);
		cnt++;
		if(cnt == n)
		{
			cout << i << endl;
			return 0;
		}
	}
	
	cout << "-1" << endl;
	return 0;
}
