#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 270;

int n, m;

int64_t memo[MAXN + 5][MAXN + 5];
int64_t rec(int sum, int last)
{
    if (sum == n)
    {
        return 1;
    }
    if (sum > n)
    {
        return 0;
    }
    if (memo[sum][last] != -1)
    {
        return memo[sum][last];
    }

    int64_t ans = 0;
    for (int x = 1; x <= last; x++)
    {
        ans += rec(sum + x, x);
    }

    memo[sum][last] = ans;
    return ans;
}

int main()
{
    cin >> n >> m;

    memset(memo, -1, sizeof(memo));
    cout << rec(0, m) << '\n';
}
