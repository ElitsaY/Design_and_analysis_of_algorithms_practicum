#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n, a[MAX], dp[MAX];

long long calc(int pos)
{
	if(pos == n)return 0;
	if(dp[pos] != -1)return dp[pos];
	if(pos == n - 1)return calc(n) + abs(a[n] - a[n - 1]);
	long long ans = min(calc(pos + 1) + abs(a[pos] - a[pos + 1]), calc(pos + 2) + abs(a[pos] - a[pos + 2]));
	
	return dp[pos] = ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		dp[i] = -1;
		cin >> a[i];
	}
	
	cout << calc(1) << endl;	
	
	return 0;
}
