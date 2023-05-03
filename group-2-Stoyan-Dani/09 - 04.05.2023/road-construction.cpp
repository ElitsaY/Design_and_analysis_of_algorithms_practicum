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
    int maxSize, compCnt;
    int parent[MAXN + 5];
    int sz[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        this->maxSize = 1;
        this->compCnt = n;
        for (int x = 1; x <= n; x++)
        {
            this->sz[x] = 1;
            this->parent[x] = x;
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

        compCnt--;
        maxSize = max(maxSize, sz[u]);

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

    DSU *T = new DSU(n);
    for (int i = 0; i < m; i++)
    {
       int u, v;
       cin >> u >> v;

        T->Union(u, v);
        cout << T->compCnt << " " << T->maxSize << '\n';
    }

}
