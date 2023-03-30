/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/105
 * @date 16/03/2023
 * 
*/

#include <cstdio>
#include <deque>


using Pair = std::pair<int, int>;

int n, k;
long long int FIRST, MUL, ADD, MOD;


int main()
{
    scanf("%d%d %lld%lld%lld%lld", &n, &k, &FIRST, &MUL, &ADD, &MOD);

    long long int res = FIRST;
    int curDay = 1;
    std::deque<Pair> dq;
    dq.push_front({FIRST, 0});

    for (; curDay < k; ++curDay)
    {
        FIRST = (FIRST * MUL + ADD) % MOD;

        while (!dq.empty() && dq.back().first <= FIRST)
        {
            dq.pop_back();
        }
        dq.push_back({FIRST, curDay});
        res += dq.front().first;
    }

    for (; curDay < n; ++curDay)
    {
        FIRST = (FIRST * MUL + ADD) % MOD;

        if (dq.front().second == curDay - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first <= FIRST)
        {
            dq.pop_back();
        }
        dq.push_back({FIRST, curDay});
        res += dq.front().first;
    }


    printf("%lld", res);

    return 0;
}