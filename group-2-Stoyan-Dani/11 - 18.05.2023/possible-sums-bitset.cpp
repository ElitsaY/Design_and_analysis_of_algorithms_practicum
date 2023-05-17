#include <iostream>
#include <bitset>

using namespace std;

const int MAX_N = 100;
const int MAX_A = 100;
const int MAX_SUM = MAX_N * MAX_A;

int n;
int a[MAX_N + 5];

bitset<MAX_SUM + 5> dp;

void solveTestcase()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp.reset();
    for (int i = n - 1; i >= 0; i--)
    {
        dp |= (dp << a[i]);
        dp[a[i]] = true;
    }

    int ans = dp.count();
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
