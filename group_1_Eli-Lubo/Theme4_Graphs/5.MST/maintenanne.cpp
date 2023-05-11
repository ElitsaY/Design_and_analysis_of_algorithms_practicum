/**
 * @author Lyuben Georgiev
 * @brief Problem Поддръжка: https://judge.openfmi.net/practice/open_contest?contest_id=86
 * @date 11/05/2023
 * 
*/

#include <cstdio>
#include <algorithm>

struct Edge
{
    int a;
    int b;
    int weight;
    int idx;

    bool operator <(const Edge &other)
    {
        return weight < other.weight;
    }
};

int n, m;
Edge edges[6001];
int parent[201];
int height[201];

void makeSets()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
        height[i] = 0;
    }
}

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

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].weight);
        edges[i].idx = i;
    }


    std::sort(edges, edges + m);

    for (int maxIdx = 1; maxIdx <= m; ++maxIdx)
    {
        makeSets();
        long long total = 0LL;
        int components = n;
        for (int i = 0; i < m && components != 1; ++i)
        {
            if (edges[i].idx < maxIdx)
            {
                int ra = findSet(edges[i].a), rb = findSet(edges[i].b);
                if (ra != rb)
                {
                    --components;
                    unionSets(ra, rb);
                    total += (long long)edges[i].weight;
                }
            }
        }

        printf("%lld\n", components == 1 ? total : -1);
    }

    return 0;
}
/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2
*/