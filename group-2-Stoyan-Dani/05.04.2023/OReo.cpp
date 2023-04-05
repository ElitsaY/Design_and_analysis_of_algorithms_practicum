#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

int n, k, a[MAX], c[MAX][32];

long long ans, pr[MAX][32];

long long calc(int l, int r)
{
	long long a = 0, b = 0;
	if(l != 0)for(int i = 0; i < 31; i++)a += ((pr[r][i] - pr[l - 1][i]) > 0) * (1 << i);
	else for(int i = 0; i < 31; i++)a += (pr[r][i] > 0) * (1 << i);
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 31; j++)c[i][j] = ((1 << j) & a[i]);
		
	}
	for(int i = 0; i < 31; i++)pr[0][i] = c[0][i];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < 31; j++)pr[i][j] = pr[i - 1][j] + c[i][j];
	}
	
	int j = 0;
	for(int i = 0; i < n; i++)
	{
		while(j < n && calc(i, j) < k)j++;
		if(j == n)break;
		ans += (n - j);
	}
	
	cout << ans << endl;
	return 0;
	
}
