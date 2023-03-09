/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/105
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <deque>


using Pair = std::pair<int, int>;

int n, k;
long long int FIRST, MUL, ADD, MOD, result;


int main()
{
    scanf("%d %d %lld %lld %lld %lld", &n, &k, &FIRST, &MUL, &ADD, &MOD);

    int curDay = 0;
    std::deque<Pair> dq;

    for (; curDay < k; ++curDay)
    {
        while (!dq.empty() && dq.back().first <= FIRST)
        {
            dq.pop_back();
        }
        dq.push_back({FIRST, curDay});
        result += dq.front().first;

        FIRST = (FIRST * MUL + ADD) % MOD;
    }

    for (; curDay < n; ++curDay)
    {
        if (!dq.empty() && dq.front().second <= curDay - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().first <= FIRST)
        {
            dq.pop_back();
        }
        dq.push_back({FIRST, curDay});
        result += dq.front().first;

        FIRST = (FIRST * MUL + ADD) % MOD;
    }

    printf("%lld", result);

    return 0;
}