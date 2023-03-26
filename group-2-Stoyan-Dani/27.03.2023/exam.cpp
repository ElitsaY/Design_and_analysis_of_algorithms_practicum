#include <iostream>

using namespace std;

int64_t sumUpTo(int64_t n)
{
    return (n * (n + 1)) / 2;
}

int64_t sumOfrange(int64_t l, int64_t r)
{
    return sumUpTo(r) - sumUpTo(l - 1);
}

int64_t n, f;

int main()
{
    cin >> n >> f;

    int64_t l = f, r = 1e10, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (sumOfrange(f, mid) >= n)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (sumOfrange(f, l) >= n)
    {
        cout << l - f + 1 << '\n';
    }
    else
    {
        cout << r - f + 1 << '\n';
    }
}
