/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/19
 * @date 25/05/2023
 * 
*/

#include <cstdio>
#include <algorithm>

const long long MOD = 1000000007;

long long n;
long long ways[100001];

int main()
{
    scanf("%lld", &n);
    ways[3] = ways[4] = ways[5] = 1;

    long long sum = 0;
    for (int i = 6; i <= n; ++i)
    {
        sum = (sum + ways[i-3]) % MOD;
        ways[i] = (sum + 1LL) % MOD;
    }

    printf("%lld", ways[n]);

    return 0;
}