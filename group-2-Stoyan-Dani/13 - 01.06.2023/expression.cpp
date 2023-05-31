#include <iostream>

using namespace std;

int n, k;

int64_t memo[85];
int64_t solve(int val)
{
    if (val > n)
    {
        return 0;
    }
    if (val == n)
    {
        return 1;
    }
    if (memo[val] != -1)
    {
        return memo[val];
    }

    int64_t ans = 0;
    for (int x = 2; x <= k; x++)
    {
        ans += solve(val + x);
        if (val != 0)
        {
            ans += solve(val * x);
        }
    }

    memo[val] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    fill(memo, memo + n + 1, -1);
    cout << solve(0) << '\n';
}
