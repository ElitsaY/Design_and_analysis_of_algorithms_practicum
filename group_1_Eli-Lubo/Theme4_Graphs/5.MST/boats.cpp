/**
 * @author Lyuben Georgiev
 * @brief Problem: https://arena.olimpiici.com/#/catalog/41/problem/100077
 * @date 17/05/2023
 * 
*/

#include <cstdio>
#include <vector>
#include <algorithm>


struct Edge
{
    int a;
    int b;
    int w;
};


int n, m, k, u, v;
Edge edges[100001];
std::vector<std::pair<int, int>> adjList[1001];
int parent[1001];
int height[1001];
bool visited[1001];

int findSet(int v)
{
    if (v == parent[v])
    {
        return v;
    }

    return parent[v] = findSet(parent[v]);
}

void unionSets(int u, int v)
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

int dfs(int u)
{
    visited[u] = true;

    for (std::pair<int, int> &p : adjList[u])
    {
        if (p.first == v)
        {
            visited[u] = false;

            return p.second;
        }

        if (!visited[p.first])
        {
            int res = dfs(p.first);
            if (res)
            {
                visited[u] = false;

                return std::min(res, p.second);
            }
        }
    }

    visited[u] = false;

    return 0;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].w);
    }

    std::sort(edges, edges + m, [](const Edge &e1, const Edge &e2) {
        return e1.w > e2.w;
    });
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    int components = n;
    for (int i = 0; i < m && components != 1; ++i)
    {
        int ra = findSet(edges[i].a);
        int rb = findSet(edges[i].b);

        if (ra != rb)
        {
            unionSets(ra, rb);
            --components;
            adjList[edges[i].a].push_back({edges[i].b, edges[i].w});
            adjList[edges[i].b].push_back({edges[i].a, edges[i].w});
        }
    }

    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &u, &v);

        printf("%d\n", dfs(u));
    }

    return 0;
}