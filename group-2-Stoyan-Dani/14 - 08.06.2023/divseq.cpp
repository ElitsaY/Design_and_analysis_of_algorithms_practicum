#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int64_t mod = 1e9 + 9;
const int MAXN = 1000;
const int MAXK = 1000;

int n, k;

vector<int> divisors[MAXK + 5];

void init()
{
    for (int d = 1; d <= k; d++)
    {
        for (int x = d; x <= k; x += d)
        {
            divisors[x].push_back(d);
        }
    }
}

int memo[MAXN + 5][MAXK + 5];
int64_t rec(int ind, int last)
{
    if (ind == n)
    {
        return 1;
    }
    if (memo[ind][last] != -1)
    {
        return memo[ind][last];
    }

    int64_t ans = 0;
    for (int x : divisors[last])
    {
        ans += rec(ind + 1, x);
    }
    for (int x = last * 2; x <= k; x += last)
    {
        ans += rec(ind + 1, x);
    }
    ans %= mod;

    memo[ind][last] = ans;
    return ans;
}

int main()
{
    cin >> n >> k;

    init();

    memset(memo, -1, sizeof(memo));
    cout << rec(0, 1) << '\n';
}
