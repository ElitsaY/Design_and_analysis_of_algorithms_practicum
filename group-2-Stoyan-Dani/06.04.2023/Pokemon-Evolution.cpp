#include <bits/stdc++.h>

using namespace std;

long long n, m, x, y, ans;

int main()
{
	cin >> n >> m >> x >> y;
	
	long long l = 0, r = n, mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(mid * x <= m + y * (n - mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	
	return 0; 
}
