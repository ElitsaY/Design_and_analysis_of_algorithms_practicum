#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e6;

int n, k;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    multiset <int> ms;
    for (int i = 0; i < k; i++)
    {
        ms.insert(a[i]);
    }

    int ans = *ms.begin();
    for (int i = k; i < n; i++)
    {
        ms.erase(ms.find(a[i - k]));
        ms.insert(a[i]);

        ans = max(ans, *ms.begin());
    }

    cout << ans << '\n';
}
