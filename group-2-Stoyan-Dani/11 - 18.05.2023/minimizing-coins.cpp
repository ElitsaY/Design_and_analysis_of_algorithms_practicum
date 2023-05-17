#include <iostream>

using namespace std;

const int MAXN = 100;
const int MAX_SUM = 1e6;
const int inf = 1e9;

int n, sum;
int c[MAXN + 5];

int dp[MAX_SUM + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> sum;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    dp[0] = 0;
    for (int x = 1; x <= sum; x++)
    {
        dp[x] = inf ;
        for (int i = 0; i < n; i++)
        {
            if (c[i] <= x)
            {
                dp[x] = min(dp[x], dp[x - c[i]] + 1);
            }
        }
    }

    if (dp[sum] == inf)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << dp[sum] << '\n';
    }
}
