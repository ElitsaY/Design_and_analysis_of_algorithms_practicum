#include <bits/stdc++.h>

using namespace std;

#define MAX 21000

int n, a[MAX], dp[MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(a[i] == a[j] + 1)dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}
