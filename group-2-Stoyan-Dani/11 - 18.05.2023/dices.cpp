#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

#define MAX 1010000

long long dp[MAX];

long long calc(int n)
{
	if(n < 0)return 0;
	if(n == 0)return 1;
	if(dp[n] != 0)return dp[n];
	long long ans = 0;
	for(int i = 1; i <= 6; i++)ans += calc(n - i);
	return dp[n] = ans % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	
	cin >> n;
	cout << calc(n) << endl;
	
	return 0;
}
