#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

const int MAXN = 2e5;

int ans[MAXN + 5];

struct DSU
{
    int parent[MAXN + 5];
    list<int> id2Parents[MAXN + 5];
    list<int> queryIds[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        for (int x = 1; x <= n; x++)
        {
            sz[x] = 1;
            parent[x] = x;
        }
    }

    void addQuery(int a, int b, int id)
    {
        if (Find(a) != Find(b))
        {
            queryIds[Find(a)].push_back(id);
            queryIds[Find(b)].push_back(id);
            id2Parents[id].push_back(Find(a));
            id2Parents[id].push_back(Find(b));
        }
        else
        {
            ans[id] = 0;
        }
    }

    int Find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        parent[x] = Find(parent[x]);
        return parent[x];
    }

    bool Union(int u, int v, int ind)
    {
        u = Find(u);
        v = Find(v);
        if (u == v)
        {
            return false;
        }

        if (queryIds[u].size() < queryIds[v].size())
        {
            swap(u, v);
        }

        for (int id : queryIds[v])
        {
            id2Parents[id].erase(find(id2Parents[id].begin(), id2Parents[id].end(), v));
            id2Parents[id].push_back(u);

            if (id2Parents[id].front() == id2Parents[id].back())
            {
                if (ans[id] == -1)
                {
                    ans[id] = ind + 1;
                }
            }
            else
            {
                queryIds[u].push_back(id);
            }
        }

        parent[v] = u;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, Q;
    cin >> n >> m >> Q;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    DSU T(n);
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;

        ans[i] = -1;
        T.addQuery(a, b, i);
    }

    for (int i = 0; i < m; i++)
    {
        T.Union(edges[i].first, edges[i].second, i);
    }

    for (int i = 0; i < Q; i++)
    {
        cout << ans[i] << '\n';
    }
}
