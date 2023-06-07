#include <iostream>
#include <cstring>

using namespace std;

const int64_t mod = 1e9 + 9;
const int MAXN = 1000;
const int MAXK = 1000;

int n, k;

int memo[MAXN + 5][MAXK + 5];
int64_t rec(int ind, int last)
{
    if (ind == n)
    {
        return 1;
    }
    if (memo[ind][last] != -1)
    {
        return memo[ind][last];
    }

    int64_t ans = 0;
    for (int x = 1; x <= k; x++)
    {
        if (last % x == 0 || x %  last == 0)
        {
            ans += rec(ind + 1, x);
        }
    }
    ans %= mod;

    memo[ind][last] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    memset(memo, -1, sizeof(memo));
    cout << rec(0, 1) << '\n';
}
