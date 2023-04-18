#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1e6;

int n, k;
int a[MAXN + 5];

bool check(int x)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= x)
        {
            len++;
            if (len >= k)
            {
                return true;
            }
        }
        else
        {
            len = 0;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = 1e9, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (check(r))
    {
        cout << r << '\n';
    }
    else
    {
        cout << l << '\n';
    }
}
