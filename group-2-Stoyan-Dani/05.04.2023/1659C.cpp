#include <bits/stdc++.h>

using namespace std;

#define MAX 210000

long long n, a, b, m[MAX], pr[MAX], ans;

void solve()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)cin >> m[i];
	pr[n] = 0;
	for(int i = n ; i >= 0; i--)
	{
		if(i < n)pr[i] = pr[i + 1] + (n - i) * (m[i + 1] - m[i]);
	}
	ans = LLONG_MAX / 100;
	for(int i = 0; i <= n; i++)
	{
		ans = min(ans, m[i] * (a + b) + pr[i] * b);
	}
	cout << ans << endl;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++)solve();	
	
	return 0;
}

/*

1
11 27182 31415
16 18 33 98 874 989 4848 20458 34365 38117 72030

75

*/
