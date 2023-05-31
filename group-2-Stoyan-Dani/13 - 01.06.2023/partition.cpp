#include <iostream>

using namespace std;

const int MAXN = 200;
const int MAXA = 1000;

int n;
int a[MAXN + 5];

bool dp[MAXN * MAXA + 5];

void solveTestcase()
{
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 != 0)
    {
        cout << "0" << '\n';
        return;
    }

    fill(dp, dp + sum + 1, false);

    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int x = sum / 2; x >= a[i]; x--)
        {
            dp[x] |= dp[x - a[i]];
        }
    }

    cout << dp[sum / 2] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--)
    {
        solveTestcase();
    }
}
