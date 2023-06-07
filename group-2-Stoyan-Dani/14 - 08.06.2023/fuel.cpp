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

    int64_t sum = 0, ptr = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr < i && a[i] - a[ptr] > l)
        {
            sum = (sum - dp[ptr] + mod) % mod;
            ptr++;
        }

        dp[i] = sum;
        if (a[i] <= l)
        {
            dp[i] = (dp[i] + 1) % mod;
        }

        sum = (sum + dp[i]) % mod;
    }

    cout << dp[n - 1] << '\n';
}
