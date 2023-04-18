#include <bits/stdc++.h>

using namespace std;

#define MAX 155

int t, n, m, mat[MAX][MAX], x;

bool okay(int days)
{
	int days_needed = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(mat[i][j] > days)
			{
				days_needed += ceil((mat[i][j] - days) * (1.0 / (x - 1)));
			}
		}
	}
	return (days >= days_needed);
}

void solve()
{
	cin >> n >> m >> x;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)cin >> mat[i][j];
	}
	int l = 0, r = 10000 * 150 * 152, mid, opt;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(okay(mid))
		{
			r = mid - 1;
			opt = mid;
		}
		else 
		{
			l = mid + 1;
		}
	}
	cout << opt << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		solve();
	}
	
	
	return 0;
}
