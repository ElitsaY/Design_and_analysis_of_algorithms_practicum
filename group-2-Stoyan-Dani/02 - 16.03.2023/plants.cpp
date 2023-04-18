#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

int n;

pair<int, int> plants[MAX];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)cin >> plants[i].second;
    for(int i = 0; i < n; i++)cin >> plants[i].first;

    sort(plants, plants + n, greater< pair<int, int> >());

    int ans = 0, plantTimes = 0;

    for(int i = 0; i < n; i++)
    {

        plantTimes += plants[i].second;
        ans = max(ans, plantTimes + plants[i].first);

    }
    cout << ans << endl;
    return 0;
}
