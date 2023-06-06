#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;

int n, k;

int64_t memo[MAXN + 5][MAXN + 5][MAXN + 5];
int64_t rec(int ind, int sum, int last)
{
    if (ind > k)
    {
        return 0;
    }
    if (sum == n)
    {
        if (ind == k)
        {
            return 1;
        }

        return 0;
    }
    if (sum > n)
    {
        return 0;
    }
    if (memo[ind][sum][last] != -1)
    {
        return memo[ind][sum][last];
    }

    int64_t ans = 0;
    for (int x = 1; x <= last; x++)
    {
        ans += rec(ind + 1, sum + x, x);
    }

    memo[ind][sum][last] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    memset(memo, -1, sizeof(memo));
    cout << rec(0, 0, n) << '\n';
}

