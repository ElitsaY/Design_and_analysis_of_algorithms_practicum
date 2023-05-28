#include <bits/stdc++.h>

using namespace std;

#define MAX 10100

int n, a[MAX], b[MAX], c[MAX], dp[MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i] >> a[i] >> b[i];
		
		dp[i] = c[i];
		for(int j = 1; j < i; j++)
		{
			if(a[i] <= a[j] && b[i] <= b[j] || b[i] <= a[j] && a[i] <= b[j])
				dp[i] = max(dp[i], dp[j] + c[i]);
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans << endl;
	return 0;
}
