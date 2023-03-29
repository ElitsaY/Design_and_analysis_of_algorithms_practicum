#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

int n;
int64_t t;
int a[MAXN + 5];

int64_t pref[MAXN + 5];

void init()
{
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
}

int64_t getSum(int l, int r)
{
    if (l == 0)
    {
        return pref[r];
    }
    return pref[r] - pref[l - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    init();

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = n - 1, mid;
        while (l + 1 < r)
        {
            mid = (l + r) / 2;

            if (getSum(i, mid) <= t)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        if (getSum(i, r) <= t)
        {
            maxLen = max(maxLen, r - i + 1);
        }
        else if (getSum(i, l) <= t)
        {
            maxLen = max(maxLen, l - i + 1);
        }
    }

    cout << maxLen << '\n';
}
