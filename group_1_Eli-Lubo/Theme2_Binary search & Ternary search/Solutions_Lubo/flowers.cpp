/**
 * @author Lyuben Georgiev
 * @brief Problem Flowers: https://judge.openfmi.net/practice/open_contest?contest_id=183
 * @date 23/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


long long int n, len, interval, first, mul, add;
long long int arr[100420];

void genFirstK(int k)
{
    arr[0] = 0;
    arr[1] = first;
    for (int i = 2; i <= k; ++i)
    {
        arr[i] = (arr[i-1]*mul + add) % (len + 1LL);
    }
    arr[k+1] = len;
}

int maxDist(int k)
{
    long long int dist = -1;
    for (int i = 1; i < k; ++i)
    {
        dist = std::max(dist, arr[i] - arr[i-1]);
    }

    return dist;
}

int main()
{
    scanf("%lld %lld %lld %lld %lld %lld", &n, &len, &interval, &first, &mul, &add);

    int l = 1, r = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        genFirstK(m);
        std::sort(arr, arr + m + 2);
        if (maxDist(m + 2) <= interval)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d", l > n ? -1 : l);

    return 0;
}