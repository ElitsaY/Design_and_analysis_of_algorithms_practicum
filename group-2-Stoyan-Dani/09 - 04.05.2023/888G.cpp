#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int inf = 1e9;
const int MAXN = 2e5;
const int MAXBIT = 30;

struct NumberSet
{
    set<int> bit2PartialNumbers[MAXBIT + 5];

    void add(int x)
    {
        int mask = 0;
        for (int bit = MAXBIT; bit >= 0; bit--)
        {
            mask |= (1 << bit);
            bit2PartialNumbers[bit].insert(x & mask);
        }
    }

    bool isInside(int x, int bit)
    {
        int mask = 0;
        for (int b = MAXBIT; b >= bit; b--)
        {
            mask |= (1 << b);
        }

        return bit2PartialNumbers[bit].count(x & mask);
    }
};

int n;
int a[MAXN + 5];

int findSplitPoint(int l, int r, int bit)
{
    for (int i = l; i <= r; i++)
    {
        if (((a[i] >> bit) & 1) != ((a[l] >> bit) & 1))
        {
            return i - 1;
        }
    }

    return r;
}

int findMinXor(int l, int r, int mid)
{
    NumberSet s;
    for (int i = l; i <= mid; i++)
    {
        s.add(a[i]);
    }

    int ans = inf;
    for (int i = mid + 1; i <= r; i++)
    {
        int currMinXor = 0;
        for (int bit = MAXBIT; bit >= 0; bit--)
        {
            if (!s.isInside(currMinXor ^ a[i], bit))
            {
                currMinXor |= (1 << bit);
            }
        }

        ans = min(ans, currMinXor);
    }

    return ans;
}

int64_t solve(int l, int r, int bit)
{
    if (bit == -1)
    {
        return 0;
    }
    if (l > r)
    {
        return 0;
    }


    int mid = findSplitPoint(l, r, bit);
    if (mid == r)
    {
        return solve(l, r, bit - 1);
    }

    int64_t ans = 0;
    ans += findMinXor(l, r, mid);
    ans += solve(l, mid, bit - 1) + solve(mid + 1, r, bit - 1);

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    cout << solve(0, n - 1, MAXBIT) << '\n';
}
