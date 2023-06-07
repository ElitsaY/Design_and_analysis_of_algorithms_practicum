#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int n, m, weight[MAX];

double dp[MAX][MAX], value[MAX];

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


int main()
{
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)cin >> weight[i] >> value[i];
	
	fill_dp();
	cout << fixed << setprecision(2) << dp[n][m] << endl;

	return 0;
}

/*

*/
