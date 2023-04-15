#include <bits/stdc++.h>

using namespace std;

#define MAX 1010000

long long n, a[MAX], l, r, ans, sl, sr, sum;

map<long long, long long> m;

void solve()
{
	
	cin >> n; 
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = n - 1; i >= 0; i--)
	{
		sum += a[i];
		m[sum] = i;
	}
	sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += a[i];
		if(m.count(sum) && m[sum] > i)ans = max(ans, i + 1 + (n - m[sum]));
	}
	cout << ans << endl;
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	solve();
	
	return 0;
}


