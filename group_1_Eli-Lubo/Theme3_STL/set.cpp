/**
 * @author Lyuben Georgiev
 * @brief Problem Set: https://judge.openfmi.net/practice/open_contest?contest_id=140
 * @date 07/04/2023
 * 
*/

#include <cstdio>
#include <algorithm>
#include <unordered_set>

int n;
long long k;
long long arr[100001];
std::unordered_set<long long> beautifulSet;

int main()
{
    scanf("%lld %lld", &n, &k);

    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
    }
    std::sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] % k == 0)
        {
            if (!beautifulSet.count(arr[i] / k))
            {
                beautifulSet.insert(arr[i]);
            }
        }
        else
        {
            beautifulSet.insert(arr[i]);
        }
    }

    printf("%d", beautifulSet.size());

    return 0;
}