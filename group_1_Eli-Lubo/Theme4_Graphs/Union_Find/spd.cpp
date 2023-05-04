#include <cstdio>
#include <algorithm>


struct Edge
{
    int a;
    int b;
    int w;

    bool operator <(const Edge &e)
    {
        return w < e.w;
    }
};


int n, m;
Edge edges[10001];
int parent[1001];
int height[1001];

int root(int node)
{
    int rootNode = node;
    while (rootNode != parent[rootNode])
    {
        rootNode = parent[rootNode];
    }

    parent[node] = rootNode;

    return rootNode;
}

void join(int u, int v)
{
    if (height[v] > height[u])
    {
        std::swap(u, v);
    }
    else if (height[v] == height[u])
    {
        ++height[u];
    }
    parent[v] = parent[u];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    std::sort(edges, edges + m);

    int minDist = 30001, resLow, resHigh;
    for (int i = 0 ; i < m; ++i)
    {
        // Kruskal
        for (int k = 1; k <= n; ++k)
        {
            parent[k] = k;
            height[k] = 0;
        }
        int components = n;

        for (int j = i; j < m; ++j)
        {
            const auto [a, b, w] = edges[j];
            int rootA = root(a);
            int rootB = root(b);

            if (rootA != rootB)
            {
                join(rootA, rootB);
                --components;
                if (components == 1)
                {
                    int low = edges[i].w;
                    int high = w;
                    if (high - low < minDist)
                    {
                        minDist = high - low;
                        resLow = low;
                        resHigh = high;
                    }
                }
            }
        }
    }

    printf("%d %d", resLow, resHigh);

    return 0;
}