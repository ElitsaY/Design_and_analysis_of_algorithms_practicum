#include <iostream>

using namespace std;

const int MAX_N = 500;
const int64_t mod = 1e9 + 7;

int memo[MAX_N][MAX_N][MAX_N];

int64_t rec(int n, int k, int last)
{
    if (n < 0)
    {
        return 0;
    }
    if (k == 0)
    {
        if (n == 0)
        {
            return 1;
        }

        return 0;
    }
    if (memo[n][k][last] != -1)
    {
        return memo[n][k][last];
    }

    int64_t ans = 0;
    for (int x = last; x >= 1; x--)
    {
        ans += rec(n - x, k - 1, x);
    }
    ans %= mod;

    memo[n][k][last] = ans;
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int p = 0; p <= n; p++)
            {
                memo[i][j][p] = -1;
            }
        }
    }

    cout << rec(n, k, n) << '\n';
}
