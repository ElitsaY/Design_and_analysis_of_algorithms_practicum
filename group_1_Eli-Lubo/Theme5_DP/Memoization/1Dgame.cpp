/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/174
 * @date 01/06/2023
 * 
*/

#include <cstdio>
#include <algorithm>

const long long UNVISITED = -1e16;


int n;
long long arr[501];
long long dp[501][501][2];

long long solve(int moves, int pos, bool forward)
{
    if (dp[moves][pos][forward] != UNVISITED)
    {
        return dp[moves][pos][forward];
    }

    long long best = arr[pos], sum = arr[pos];
    for (int i = 1; i <= moves; ++i)
    {
        int newPos = pos + (forward ? i : -i);
        best = std::max(best, sum + solve(i - 1, newPos, !forward));
        sum += arr[newPos];
    }

    return dp[moves][pos][forward] = best;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
    }

    for (int i = 1; i < 501; ++i)
    {
        for (int j = 0; j < 501; ++j)
        {
            dp[i][j][0] = dp[i][j][1] = UNVISITED;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        dp[0][i][0] = dp[0][i][1] = arr[i];
    }

    printf("%lld", solve(n - 1, 0, true));

    return 0;
}