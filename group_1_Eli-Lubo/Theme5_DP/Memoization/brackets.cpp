#include <cstdio>

const long long MOD = 1001027;

int n, k;
char s[2002];
long long dp[2002][2002]; // [do kude sum][zatvarqshti - otvarqshti]

long long solve(int pos, int diff)
{
    if (dp[pos][diff] != -1)
    {
        return dp[pos][diff];
    }

    if (pos == 1)
    {
        if (diff == 1)
        {
            return dp[pos][diff] = 1;
        }

        return dp[pos][diff] = 0;
    }

    if (s[pos] == '(')
    {
        if (diff == 0)
        {
            return dp[pos][diff] = 0;
        }

        return dp[pos][diff] = solve(pos - 1, diff - 1);
    }
    else
    {
        if (diff == 0) // We need to place ')' at s[pos]
        {
            return dp[pos][diff] = solve(pos - 1, 1);
        }

        return dp[pos][diff] = (solve(pos - 1, diff + 1) + solve(pos - 1, diff - 1)) % MOD;
    }
}

int main()
{
    scanf("%d %d", &n, &k);

    for (int i = 0; i < 2002; ++i)
    {
        for (int j = 0; j < 2002; ++j)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < k; ++i)
    {
        int pos;
        scanf("%d", &pos);
        s[pos] = '(';
    }

    printf("%lld", solve(2 * n, 0));

    return 0;
}