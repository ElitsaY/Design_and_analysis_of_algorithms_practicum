#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

const int MAXN = 2e5;

struct ParentInfo
{
    int x;
    int day;

    ParentInfo(){}
    ParentInfo(int x, int day) : x(x), day(day) {}
};

int ans[MAXN + 5];

struct DSU
{
    int sz[MAXN + 5];
    ParentInfo parent[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        for (int x = 1; x <= n; x++)
        {
            sz[x] = 1;
            parent[x] = ParentInfo(x, 0);
        }
    }

    int Find(int x)
    {
        if (x == parent[x].x)
        {
            return x;
        }

        return Find(parent[x].x);
    }

    bool Union(int u, int v, int day)
    {
        u = Find(u);
        v = Find(v);
        if (u == v)
        {
            return false;
        }

        if (sz[u] < sz[v])
        {
            swap(u, v);
        }

        parent[v] = ParentInfo(u, day);
        sz[u] += sz[v];
        return true;
    }
};

void loadParentHistory(int x, vector<ParentInfo> &v, const DSU& T)
{
    while (T.parent[x].x != x)
    {
        v.emplace_back(x, T.parent[x].day);
        x = T.parent[x].x;
    }

    v.push_back(T.parent[x]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, Q;
    cin >> n >> m >> Q;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    DSU T(n);
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        ans[i] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        T.Union(edges[i].first, edges[i].second, i + 1);
    }

    for (int i = 0; i < Q; i++)
    {
        if (queries[i].first == queries[i].second)
        {
            cout << "0" << '\n';
            continue;
        }
        if (T.Find(queries[i].first) != T.Find(queries[i].second))
        {
            cout << "-1" << '\n';
            continue;
        }

        vector<ParentInfo> aHistory, bHistory;
        loadParentHistory(queries[i].first, aHistory, T);
        loadParentHistory(queries[i].second, bHistory, T);

        reverse(aHistory.begin(), aHistory.end());
        reverse(bHistory.begin(), bHistory.end());

        int diffInd = 0;
        while (diffInd < aHistory.size() && diffInd < bHistory.size()
               && aHistory[diffInd].x == bHistory[diffInd].x)
        {

            diffInd++;
        }

        int ansDay = 0;
        if (diffInd < aHistory.size()) ansDay = max(ansDay, aHistory[diffInd].day);
        if (diffInd < bHistory.size()) ansDay = max(ansDay, bHistory[diffInd].day);
        cout << ansDay << '\n';
    }
}
/*
3 2 1
1 2
2 3
1 3
*/
