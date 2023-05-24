#include <iostream>

using namespace std;

const int MAX_N = 1e6;
const int64_t inf = 1e15;

int n;
int h[MAX_N + 5];

int64_t dp[MAX_N + 5];

int64_t rec(int ind)
{
    if (ind == n - 1)
    {
        return 0;
    }

    int64_t ans = inf;
    if (ind + 1 < n)
    {
        ans = min(ans, rec(ind + 1) + abs(h[ind] - h[ind + 1]));
    }
    if (ind + 2 < n)
    {
        ans = min(ans, rec(ind + 2) + abs(h[ind] - h[ind + 2]));
    }

    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << rec(0) << '\n';
}

