#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e5;
const int MAXM = 2e5;

struct Edge
{
    int u, v, w;

    Edge() {}
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

struct DSU
{
    int parent[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        for (int x = 1; x <= n; x++)
        {
            parent[x] = x;
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

    bool Union(int u, int v)
    {
        u = Find(u);
        v = Find(v);
        if (u == v)
        {
            return false;
        }

        parent[v] = u;
        return true;
    }
};

int n, m;
Edge edges[MAXM + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges, edges + m,
    [](const Edge &e1, const Edge& e2)
    {
        return e1.w < e2.w;
    });

    DSU T(n);
    int64_t ans = 0;
    int addedEdges = 0;
    for (int i = 0; i < m; i++)
    {
        if (T.Find(edges[i].u) != T.Find(edges[i].v))
        {
            addedEdges++;
            ans += edges[i].w;
            T.Union(edges[i].u, edges[i].v);
        }
    }

    if (addedEdges == n - 1)
    {
        cout << ans << '\n';
    }
    else
    {
        cout << "IMPOSSIBLE" << '\n';
    }
}
