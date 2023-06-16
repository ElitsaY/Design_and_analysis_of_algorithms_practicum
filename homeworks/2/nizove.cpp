#include <bits/stdc++.h>

using namespace std;

#define MAX 2001000

int t, n, q, a, b, par[MAX], depth[MAX], sz[MAX], idx;

string s, cpy;

int find(int a)
{
    if(par[a] == -1)return a;
    return par[a] = find(par[a]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b)return ;
    if(depth[a] > depth[b])
    {
        par[b] = a;
        sz[a] += sz[b];
    }
    else
    {
        par[a] = b;
        sz[b] += sz[a];
        if(depth[a] == depth[b])depth[b]++;
    }
    return;
}


void solve()
{
    cin >> s;
    cpy = s;
    cin >> q;
    n = s.size();
    
    fill(par, par + n + 2, -1);
    fill(sz, sz + n + 2, 1);
    
    vector<pair<int, int> > v;
    for(int i = 0; i < q; i++)
    {
        cin >> a >> b;
        v.push_back({a, b});
        if(a == 2)s[b] = '#';
    }
    
    for(int i = 1; i < n; i++)
    {
        if(s[i] == '#')continue;
        if(s[i] == s[i - 1])
        {
            uni(i, i - 1);
        }
    }
    
    stack<int> ans;
    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(v[i].first == 1)ans.push(sz[find(v[i].second)]);
        else
        {
            idx = v[i].second;
            s[idx] = cpy[idx];
            if(idx > 0 && s[idx] == s[idx - 1])uni(idx, idx - 1);
            if(idx < n - 1 && s[idx] == s[idx + 1])uni(idx, idx + 1);
        }
        
    }
    while(!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solve();
    
    return 0;
}

/*

1
AAAAAAAA
7
1 0
2 3 
1 0
2 6
1 0
2 1
1 0 


*/
