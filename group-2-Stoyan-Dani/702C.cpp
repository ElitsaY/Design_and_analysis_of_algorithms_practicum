#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int n, m;
int a[MAXN + 5], b[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int ptr = 0;
    int maxR = 0;
    for (int i = 0; i < n; i++)
    {
        while (ptr + 1 < m && b[ptr + 1] <= a[i])
        {
            ptr++;
        }

        int minDist = abs(a[i] - b[ptr]);
        if (ptr + 1 < m) minDist = min(minDist, abs(a[i] - b[ptr + 1]));

        maxR = max(maxR, minDist);
    }

    cout << maxR << '\n';
}
