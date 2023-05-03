//90 точки

#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1e3;

struct Edge
{
    int u, v;

    Edge() {}
    Edge(int u, int v)
    {
        if (u > v)
        {
            swap(u, v);
        }

        this->u = u;
        this->v = v;
    }
};

bool operator <(const Edge &e1, const Edge &e2)
{
    if (e1.u != e2.u)
    {
        return e1.u < e2.u;
    }

    return e1.v < e2.v;
}

struct DSU
{
    int parent[MAXN + 5];
    int sz[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        this->reset(n);
    }

    void reset(int n)
    {
        for (int x = 1; x <= n; x++)
        {
            sz[x] = 1;
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

        if (sz[u] < sz[v])
        {
            swap(u, v);
        }

        sz[u] += sz[v];
        parent[v] = u;

        return true;
    }
};

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    DSU T(n);
    set<Edge> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        T.Union(u, v);
        edges.emplace(u, v);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1)
        {
            cout << (T.Find(u) == T.Find(v));
        }
        else if (type == 2)
        {
            T.Union(u, v);
            edges.emplace(u, v);
        }
        else
        {
            edges.erase(Edge(u, v));

            T.reset(n);
            for (const Edge &e : edges)
            {
                T.Union(e.u, e.v);
            }
        }
    }

    cout << '\n';
}
/*
9 8
1 2
3 4
5 6
7 8
9 5
7 2
8 2
6 9
8
1 1 8
1 6 2
2 7 1
1 4 7
2 2 3
1 4 7
3 3 4
1 4 7
*/
