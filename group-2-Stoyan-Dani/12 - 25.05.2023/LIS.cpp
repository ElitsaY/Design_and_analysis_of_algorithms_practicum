#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int n, a[MAX], dp[MAX], ans, par[MAX];

int main()
{
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i], 1);
		for(int j = i + 1; j <= n; j++)
		{
			if(a[j] > a[i])
			{
				if(dp[j] < dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					par[j] = i;
				}
			} 
		}
		ans = max(ans, dp[i]);
	}
	
	/*
	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)
		{
			if(a[i] > a[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		
		cout << dp[i] << " ";
	}*/
	cout << ans << endl;
	
	int node;
	for(int i = 1; i <= n; i++)if(ans == dp[i])node = i;
	
	
	
	while(node != 0)
	{
		cout << a[node] << " ";
		for(int j = node - 1; j >= 0; j--)
		{
			if(a[j] < a[node] && dp[j] == dp[node] - 1)
			{
				node = j;
				break;
			}
		}
		
	}
	cout << endl;
	return 0;
}

/*

6
50 3 10 7 40 80

*/
