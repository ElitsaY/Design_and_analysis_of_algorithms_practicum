/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/78
 * @date 04/05/2023
 * 
*/

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

Edge solve(int mid)
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        height[i] = 0;
    }

    int low = edges[mid].w;

    int cnt = n;
    for (int i = mid; i < m; ++i)
    {
        const auto [u, v, w] = edges[i];

        int ru = root(u), rv = root(v);
        if (ru != rv)
        {
            join(ru, rv);
            --cnt;
            if (cnt == 1)
                return {low, w, w - low};
        }
    }

    return {0, 0, 100000};
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = {u, v, w};
    }

    std::sort(edges, edges + m);

    Edge result = solve(0);
    for (int i = 1; i < m; ++i)
    {
        Edge res = solve(i);
        if (res.w < result.w)
        {
            result = res;
        }
    }

    printf("%d %d", result.a, result.b);

    return 0;
}