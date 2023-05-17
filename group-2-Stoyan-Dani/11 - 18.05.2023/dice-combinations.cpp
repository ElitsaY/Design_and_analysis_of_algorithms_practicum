#include <iostream>

using namespace std;

const int MAXN = 1e6;
const int64_t mod = 1e9 + 7;

int64_t dp[MAXN + 5];

int main()
{
    int n;
    cin >> n;

    dp[0] = 1;
    for (int x = 1; x <= n; x++)
    {
        for (int lastDice = 1; lastDice <= min(6, x); lastDice++)
        {
            dp[x] += dp[x - lastDice];
        }
        dp[x] %= mod;
    }

    cout << dp[n] << '\n';
}
