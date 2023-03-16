#include <iostream>

using namespace std;

#define MAX 100100

int n, m, a[MAX], b[MAX];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int i = 0; i < m; i++)cin >> b[i];

    int ans = 0, j = 0;

    for(int i = 0; i < n; i++)
    {
        while(j + 1 < m && abs(a[i] - b[j]) >= abs(a[i] - b[j + 1]))j++;
        ans = max(ans, abs(a[i] - b[j]));

    }

    cout << ans << endl;

    return 0;
}
