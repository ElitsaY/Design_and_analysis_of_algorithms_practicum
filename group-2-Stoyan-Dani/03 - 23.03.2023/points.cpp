#include <bits/stdc++.h>


using namespace std;

vector<pair<int, int> > v;

int n, l, r;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r, -1});

    }
    sort(v.begin(), v.end(), [](const pair<int, int>& l, const pair<int, int>& r)
         {
             if(l.first < r.first )return true;
             if(l.first > r.first)return false;
             return l.second > r.second;
         });

    int ans = 0, sum = 0;

    for(int i = 0; i < v.size(); i++)
    {
        sum += v[i].second;
        ans = max(sum, ans);
    }

    cout << ans << endl;
    return 0;
}
