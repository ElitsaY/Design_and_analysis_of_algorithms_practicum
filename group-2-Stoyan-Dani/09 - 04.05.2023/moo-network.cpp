#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1e5;
const int MAXY = 10;

struct Edge
{
    int u, v;
    int64_t w;

    Edge(){}
    Edge(int u, int v, int64_t w) : u(u), v(v), w(w) {}
};

struct DSU
{
    int parent[MAXN + 5];

    DSU() {}
    DSU(int n)
    {
        for (int x = 0; x < n; x++)
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

int n;
pair<int, int> a[MAXN + 5];

DSU T;
int last[MAXY + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);

    vector<Edge> edges;
    for (int y = 0; y <= MAXY; y++)
    {
        last[y] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int y = 0; y <= MAXY; y++)
        {
            if (last[y] != -1)
            {
                int64_t d = (a[last[y]].first - a[i].first) * 1LL * (a[last[y]].first - a[i].first) +
                    (a[last[y]].second - a[i].second) * 1LL * (a[last[y]].second - a[i].second);

                edges.emplace_back(last[y], i, d);
            }
        }

        last[a[i].second] = i;
    }

    sort(edges.begin(), edges.end(),
    [](const Edge &e1, const Edge &e2)
    {
        return e1.w < e2.w;
    });

    T = DSU(n);
    int64_t ans = 0;
    for (const Edge& e : edges)
    {
        if (T.Union(e.u, e.v))
        {
            ans += e.w;
        }
    }

    cout << ans << '\n';
}
/*
3
500 1
0 0
1000 0
*/
