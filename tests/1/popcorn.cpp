#include <bits/stdc++.h>
using namespace std;

#define MAX 101000

int n, k, s, p[MAX];

int l, r, mid, l1, r1, mid1, ans, idx, ans1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k >> s;
	for(int i = 1; i <= n; i++)cin >> p[i];
	for(int i = 2; i <= n; i++)p[i] += p[i - 1];
	l = 0; r = ans = INT_MAX / 2;
	while(l <= r)
	{
		
		mid = (l + r) / 2;
		idx = 1;
		for(int j = 0; j < k; j++)
		{
			l1 = idx - 1;
			ans1 = idx - 1;
			r1 = n;
			while(l1 <= r1)
			{
				mid1 = (l1 + r1) / 2;
				if(p[mid1] - p[idx - 1] > mid)r1 = mid1 - 1;
				else 
				{
					l1 = mid1 + 1;
					ans1 = max(ans1, mid1);
				}
			}
			idx = ans1 + 1;
		}
		if(idx > n)
		{
			ans = min(ans, mid);
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans / s + (ans % s > 0) << endl;
	return 0;
}
