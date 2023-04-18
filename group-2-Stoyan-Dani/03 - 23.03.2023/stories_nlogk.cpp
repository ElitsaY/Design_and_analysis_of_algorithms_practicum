#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int64_t ans = 0;
    priority_queue <pair <int, int>> pq;

    int n, k;
    cin >> n >> k;

    int64_t first, mul, add, mod;
    cin >> first >> mul >> add >> mod;

    int64_t a = first;
    for (int i = 0; i < n; i++)
    {
        pq.emplace(a, i);
        n

        ans += pq.top().first;
        a = (a*mul + add) % mod;
    }

    cout << ans << '\n';
}
