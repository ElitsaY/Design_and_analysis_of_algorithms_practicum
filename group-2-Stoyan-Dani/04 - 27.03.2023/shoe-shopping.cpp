#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

int n;
vector<int> a;

int64_t pref[MAXN + 5];

void init()
{
    sort(a.begin(), a.end());

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }
}

int64_t getSum(int l, int r)
{
    if (l==0)
    {
        return pref[r];
    }
    return pref[r] - pref[l - 1];
}

int query(int64_t m, int64_t k)
{
    int firstInd = upper_bound(a.begin(), a.end(), k) - a.begin();
    if (firstInd == 0)
    {
        return 0;
    }
    firstInd--;

    int l = 0, r = firstInd, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (getSum(mid, firstInd) <= m)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (getSum(l, firstInd) <= m)
    {
        return firstInd - l + 1;
    }
    if (getSum(r, firstInd) <= m)
    {
        return firstInd - r + 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;

    cin >> n >> Q;

    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    init();

    while(Q--)
    {
        int64_t m, k;
        cin >> m >> k;

        cout << query(m, k) << '\n';
    }
}
