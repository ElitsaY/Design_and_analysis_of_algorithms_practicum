/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/243
 * @date 01/06/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n;
int arr[1001];
long long dp[1001][1001];

long long solve(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    else if (l == r)
    {
        return dp[l][r] = n * arr[l];
    }

    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }

    return dp[l][r] = std::max((n - r + l) * arr[l] + solve(l + 1, r), (n - r + l) * arr[r] + solve(l, r - 1));
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 1001; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            dp[i][j] = -1;
        }
    }

    printf("%lld", solve(0, n-1));

    return 0;
}