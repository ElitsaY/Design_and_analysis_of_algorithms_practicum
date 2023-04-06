/**
 * @author Lyuben Georgiev
 * @brief Problem Elliot: https://judge.openfmi.net/practice/open_contest?contest_id=21
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, k, q;
long long qi;
int prices[1000001];
std::pair<long long, int> sums[1000001];

int main()
{
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &prices[i]);
    }

    for (int i = 0; i < k; ++i)
    {
        sums[0].first += prices[i];
        sums[0].second = 0;
    }

    for (int i = k; i < n; ++i)
    {
        sums[i-k+1].first = sums[i-k].first + (long long)prices[i] - (long long)prices[i-k];
        sums[i-k+1].second = i-k+1;
    }
    std::sort(sums, sums + n - k + 1);

    for (int i = n - k - 1; i >= 0; --i)
    {
        sums[i].second = std::min(sums[i].second, sums[i+1].second);
    }

    for (int i = 0; i < q; ++i)
    {
        scanf("%lld", &qi);

        std::pair<long long, int>* ptr = std::lower_bound(sums, sums + n - k + 1, qi, [](std::pair<long long, int> el, long long val){
            return el.first < val;
        });

        printf("%d\n", ptr == sums + n - k + 1 ? -1 : ptr->second);
    }

    return 0;
}