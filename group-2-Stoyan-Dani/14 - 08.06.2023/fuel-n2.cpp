#include <iostream>

using namespace std;

const int MAXN = 1e6;
const int64_t mod = 1e9 + 7;

int n, k, l;
int a[MAXN + 5];

int64_t dp[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> l;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    a[n] = k;
    n++;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= l)
        {
            dp[i]++;
        }

        for (int j = 0; j < i; j++)
        {
            if (a[i] - a[j] <= l)
            {
                dp[i] += dp[j];
            }
        }
        dp[i] %= mod;
    }

    cout << dp[n - 1] << '\n';
}
