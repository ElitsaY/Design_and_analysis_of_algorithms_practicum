#include <iostream>

using namespace std;

const int MAX_N = 100;
const int MAX_A = 100;
const int MAX_SUM = MAX_N * MAX_A;

int n;
int a[MAX_N + 5];

bool dp[MAX_SUM + 5];

void solveTestcase()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int x = 0; x <= MAX_SUM; x++)
    {
        dp[x] = false;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int x = MAX_SUM; x >= 0; x--)
        {
            if (a[i] <= x && dp[x - a[i]])
            {
                dp[x] = true;
            }
        }

        dp[a[i]] = true;
    }

    int ans = 0;
    for (int x = 0; x <= MAX_SUM; x++)
    {
        if (dp[x])
        {
            ans++;
        }
    }
    if (!dp[0])
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
