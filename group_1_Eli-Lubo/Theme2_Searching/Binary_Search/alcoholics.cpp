/**
 * @author Lyuben Georgiev
 * @brief Problem Алкохолици: https://judge.openfmi.net/practice/open_contest?contest_id=37
 * @date 30/03/2023
 * 
*/

#include <cstdio>


int n;
long long int dists[100001];
long long int remaining[100001];

bool good(long long int parties)
{
    long long int needed = 0;
    for (int i = 0; i < n; ++i)
    {
        needed += (parties - remaining[i]);

        if (needed != 0 && i != n-1)
        {
            // We have extra alcohol but cost of transport is too high
            if (needed <= 0 && needed + dists[i+1] - dists[i] >= 0)
            {
                needed = 0;
            }
            else // We need alcohol
            {
                needed += (dists[i+1] - dists[i]);
            }
        }
    }

    // If we have extra alcohol it is a good case
    return needed <= 0;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld %lld", &dists[i], &remaining[i]);
    }

    int l = 1, r = 1000000000;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (good(m))
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    printf("%d\n", r);

    return 0;
}