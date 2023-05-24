#include <iostream>

using namespace std;

const int64_t mod = 1e9 + 7;

const int MAX_N = 1000;

int memo[MAX_N + 5][MAX_N + 5];
int64_t solve(int n, int k)
{
    if (k < 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n == k)
    {
        return 1;
    }
    if (n < k)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    int64_t ans = (solve(n - k, k) + solve(n - 1, k - 1)) % mod;
    memo[n][k] = ans;

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            memo[i][j] = -1;
        }
    }

    cout << solve(n, k) << '\n';
}
