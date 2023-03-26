#include <iostream>

using namespace std;

const int MAXN = 1e5;

int n;
int64_t m;
int64_t a[MAXN + 5], b[MAXN + 5];

bool check(int64_t maxC)
{
    int64_t balloonsNeeded = 0;
    for (int i = 0; i < n; i++)
    {
        int64_t tolerance = maxC / b[i];
        if (a[i] >= tolerance)
        {
            balloonsNeeded += a[i] - tolerance;
        }
    }

    return balloonsNeeded <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int64_t l = 0, r = 1e18, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (check(mid) == true)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (check(l) == true)
    {
        cout << l << '\n';
    }
    else
    {
        cout << r << '\n';
    }
}
