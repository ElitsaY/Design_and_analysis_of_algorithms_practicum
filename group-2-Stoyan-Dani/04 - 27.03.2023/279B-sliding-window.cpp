#include <iostream>

using namespace std;

const int MAXN = 1e5;

int n;
int64_t t;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int64_t sum = a[0];
    int r = 0, maxLen = 0;

    for (int l = 0; l < n; l++)
    {
        while (r + 1 < n && a[r + 1] + sum <= t)
        {
            r++;
            sum += a[r];
        }

        if (sum <= t)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        sum -= a[l];
    }

    cout << maxLen << '\n';
}
