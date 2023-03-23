//не се учи в курса
//за сега...

/*
Това решение използва техниката "монотонна опашка"(monotonic queue).
Това беше и очакваното решение на състезанието.
Това е и стандартният начин за решаване на монотонно RMQ(Range Maximum Query)
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int64_t ans = 0;
    deque <pair <int, int>> dq;

    int n, k;
    cin >> n >> k;

    int64_t first, mul, add, mod;
    cin >> first >> mul >> add >> mod;


    int64_t a = first;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && dq.front().second <= i - k)
        {
            dq.pop_front();
        }

        while(!dq.empty() && dq.back().first <= a)
        {
            dq.pop_back();
        }
        dq.emplace_back(a, i);

        ans += dq.front().first;
        a = (a*mul + add) % mod;
    }

    cout << ans << '\n';
}
