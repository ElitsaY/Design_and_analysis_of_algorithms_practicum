#include <bits/stdc++.h>

using namespace std;

#define MAX 510000

long long n, k, a[MAX], ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++)cin >> a[i];
	
	sort(a, a + n, greater<int>());
	for(int i = 0; i < n; i++)
	{
		ans += a[i] * (i / k + 1);
	}
	cout << ans << endl;
	
	return 0;
}
