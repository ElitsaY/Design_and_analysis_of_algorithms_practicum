#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, dp[MAX][MAX], weight[MAX], value[MAX];

void fill_dp()
{
	for(int i = 0; i <= n; i++)dp[i][0] = 0;
	for(int i = 0; i <= m; i++)dp[0][i] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			if(weight[i] <= j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
}

void find_solution()
{
	int w = m;
	for(int i = n; i >= 1; i--)
	{
		if(w >= weight[i] && dp[i][w] == dp[i - 1][w - weight[i]] + value[i])
		{
			cout << i << " ";
			w = w - weight[i];
		}
	}
	cout << endl;
}

int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)cin >> weight[i] >> value[i];
	
	fill_dp();
	cout << dp[n][m] << endl;
	find_solution();

	return 0;
}

/*

4 5
2 3
3 4
4 5 
5 6


4 5
2 2
2 2 
2 2
2 2

*/
