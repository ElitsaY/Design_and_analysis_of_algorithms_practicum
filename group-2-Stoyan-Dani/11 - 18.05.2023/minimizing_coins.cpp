#include <bits/stdc++.h>

using namespace std;

#define MAX 105

int n, x, c[MAX], dp[1001000];

int calc(int x)
{
	if(x == 0)return 0;
	if(x < 0)return INT_MAX / 3;
	if(dp[x] != 0)return dp[x];
	int ans = INT_MAX / 3;
	for(int i = 1; i <= n; i++)ans = min(ans, 1 + calc(x - c[i]));
	return dp[x] = ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> x;
	for(int i = 1; i <= n; i++)cin >> c[i];

	int ans = calc(x);
	if(ans >= INT_MAX / 3)ans = -1;
	cout << ans << endl;

	return 0;
}
