#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int n, k, m;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector <int> gaps;
    for (int i = 0; i + 1 < n; i++)
    {
        gaps.push_back(a[i + 1] - a[i] - 1);
    }
    sort(gaps.begin(), gaps.end(), greater <int> ());

    int64_t ans = a[n - 1] - a[0] + 1;
    for (int i = 0; i < k - 1; i++)
    {
        ans -= gaps[i];
    }

    cout << ans << '\n';
}
