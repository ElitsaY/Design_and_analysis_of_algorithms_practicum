#include <iostream>

using namespace std;

int64_t a, k, b, m, x;

bool check(int64_t days)
{
    if (days - days / k > x / a) return true;
    if (days - days / m > x / b) return true;
    return (days - days / k) * a + (days - days / m) * b >= x;
}

int main()
{
    cin >> a >> k >> b >> m >> x;

    int64_t l = 0, r = 2e18, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (check(l))
    {
        cout << l << '\n';
    }
    else
    {
        cout << r << '\n';
    }
}
