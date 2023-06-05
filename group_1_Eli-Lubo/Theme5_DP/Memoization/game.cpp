#include <cstdio>
#include <algorithm>


const int NEG_INF = -1e9;

int n;
int arr[501];
int dp[501][501][2];

int solve(int moves, int cur, bool forward)
{
    if (moves == 0)
    {
        return arr[cur];
    }

    if (dp[moves][cur][forward] != NEG_INF)
    {
        return dp[moves][cur][forward];
    }

    int sum = arr[cur], bestRes = arr[cur], curRes;
    for (int steps = 1; steps <= moves; ++steps)
    {
        int newCur = cur + (forward ? steps : -steps);
        curRes = solve(steps - 1, newCur, !forward);
        bestRes = std::max(bestRes, sum + curRes);
        sum += arr[newCur];
    }

    return dp[moves][cur][forward] = bestRes;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 501; ++i)
    {
        for (int j = 0; j < 501; ++j)
        {
            dp[i][j][0] = dp[i][j][1] = NEG_INF;
        }
    }

    printf("%d", solve(n - 1, 0, true));

    return 0;
}