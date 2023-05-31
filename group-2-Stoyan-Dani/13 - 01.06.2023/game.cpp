#include <iostream>

using namespace std;

const int MAXN = 700;

int n;
int a[MAXN + 5];

int memo[MAXN + 5][MAXN + 5];
int solve(int l, int r)
{
    if (r - l + 1 <= 2)
    {
        return 0;
    }
    if (memo[l][r] != -1)
    {
        return memo[l][r];
    }

    int ans = 0;
    for (int split = l + 1; split <= r - 1; split++)
    {
        ans  = max(ans, solve(l, split) + solve(split, r) + a[split] * (a[l] + a[r]));
    }

    memo[l][r] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            memo[l][r] = -1;
        }
    }

    cout << solve(0, n - 1) << '\n';
}
