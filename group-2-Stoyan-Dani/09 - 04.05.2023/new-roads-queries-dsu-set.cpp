#include <unordered_set>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 2e5;

int ans[MAXN + 5];

struct DSU
{
    int parent[MAXN + 5];
    set<int> queryIds[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        for (int x = 1; x <= n; x++)
        {
            parent[x] = x;
        }
    }

    void addQuery(int a, int b, int id)
    {
        if (Find(a) != Find(b))
        {
            queryIds[Find(a)].insert(id);
            queryIds[Find(b)].insert(id);
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
            if (queryIds[u].count(id))
            {
                ans[id] = ind + 1;
                queryIds[u].erase(id);
            }
            else
            {
                queryIds[u].insert(id);
            }
        }
        queryIds[v].clear();

        parent[v] = u;
        return true;
    }
};


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
