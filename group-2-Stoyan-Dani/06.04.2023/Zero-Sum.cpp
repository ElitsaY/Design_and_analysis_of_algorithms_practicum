#include <bits/stdc++.h>

using namespace std;

#define MAX 11000

long long n, a[MAX], ridx;

long long ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	
	for(int i = 0; i < n; i++)
	{
		
	}
	
	int j, k;
	for(int i = 0; i < n; i++)
	{
		j = i + 1;
		k = i + 2;
		while(k < n && a[i] + a[j] + a[k] <= 0)k++;
		k--;
		if(k >= n)k = n - 1;
		ridx = k;
		for(int j = i + 1; j < n; j++)
		{
			
			while(k > j && a[i] + a[j] + a[k] >= 0)
			{
				k--;
				if(a[k + 1] != a[k] && a[i] + a[j] + a[k] == 0)ridx = k;
			}
			if(k < n - 1)k++;
			if(j < k && a[i] + a[j] + a[k] == 0)ans += (ridx - k + 1);
			
		}
	}
	cout << ans << endl;
	return 0;
}

/*

10
2 -5 2 3 -4 7 -4 0 1 -6


4
0 0 0 0

*/
