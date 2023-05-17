#include <iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_A = 100;
const int MAX_SUM = MAX_N * MAX_A;

int n;
int a[MAX_N + 5];

bool dp[2][MAX_SUM + 5];

void solveTestcase()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int x = 0; x < MAX_N * MAX_A; x++)
    {
        dp[0 & 1][x] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            for (int x = 0; x <= MAX_SUM; x++)
            {
                dp[i & 1][x] = dp[(i - 1) & 1][x];
                if (x >= a[i] && dp[(i - 1) & 1][x - a[i]])
                {
                    dp[i & 1][x] = true;
                }
            }
        }

        dp[i & 1][a[i]] = true;
    }

    int ans = 0;
    for (int x = 0; x <= MAX_SUM; x++)
    {
        if (dp[(n - 1) & 1][x])
        {
            ans++;
        }
    }
    if (!dp[(n - 1) & 1][0])
    {
        ans++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        solveTestcase();
    }
}
