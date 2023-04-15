#include <bits/stdc++.h>

using namespace std;

#define MAX 1010000

long long n, t, a[MAX], l, r, ans, suml, sumr;

void solve()
{
	cin >> n; 
	for(int i = 0; i < n; i++)cin >> a[i];
	l = 0;
	r = n - 1;
	while(l <= r + 1)
	{
		if(suml == sumr)
		{
			ans = max(ans, l + (n - 1 - r));
		}
		if(suml >= sumr)
		{
			sumr += a[r];
			r--;
		}
		else
		{
			suml += a[l];
			l++;
		}
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

