#include <bits/stdc++.h>

using namespace std;

#define MAX 1024

int n, m, a[MAX][MAX], dp[MAX][MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)cin >> a[j][i];
		
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + a[i][j];
			if(j > 1)dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
			if(j < n)dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a[i][j]);
		}
	}
	
	ans = dp[m][1];
	for(int i = 1; i <= n; i++)ans = min(ans, dp[m][i]);
	
	cout << ans << endl;
	
	return 0;
}
