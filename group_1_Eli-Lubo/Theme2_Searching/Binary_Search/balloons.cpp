/**
 * @author Lyuben Georgiev
 * @brief Problem Бонбони и балони: https://judge.openfmi.net/practice/open_contest?contest_id=176
 * @date 30/03/2023
 * 
*/

#include <cstdio>
#include <climits>


long long int n, m;
int wanted[100001];
int coef[100001];


bool good(long long int bonbonGuess)
{
    long long int neededBalloons = 0;
    for (int i = 0; i < n; ++i)
    {
        long long int rem = (long long)wanted[i] - bonbonGuess / (long long)coef[i];
        if (rem > 0)
        {
            neededBalloons += rem;
        }
    }

    return neededBalloons <= m;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &wanted[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &coef[i]);
    }

    long long int l = 0, r = LONG_MAX;
    while (l <= r)
    {
        long long m = l + (r-l) / 2;
        if (good(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%lld", l);

    return 0;
}