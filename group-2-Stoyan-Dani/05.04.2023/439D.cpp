#include <bits/stdc++.h>

using namespace std;

#define MAX 110000

long long n, m, a[MAX], b[MAX], l = 0, r = INT_MAX, m1, m2, st1, st2, ans = LLONG_MAX / 123;

long long eval(long long st)
{
	long long ans = 0;
	for(int i = 0; i < n; i++)if(a[i] < st)ans += st - a[i];
	for(int i = 0; i < m; i++)if(b[i] > st)ans += b[i] - st;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < m; i++)cin >> b[i];
	
	while(l <= r)
	{
		m1 = l + (r - l + 1) / 3;
		m2 = l + 2 * (r - l + 1) / 3;
		st1 = eval(m1);
		st2 = eval(m2);
		if(st1 > st2)
		{
			ans = min(ans, st2);
			l = m1 + 1;
		}
		else
		{
			ans = min(ans, st1);
			r = m2 - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
