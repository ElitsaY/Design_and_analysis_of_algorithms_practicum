/**
 * @author Lyuben Georgiev
 * @brief Problem Хипертелепорт: https://judge.openfmi.net/practice/open_contest?contest_id=88
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

    bool operator <(const Edge &other)
    {
        return weight < other.weight;
    }
};

int n, m, k, eCnt;
char cities[1001][51];
Edge edges[500001];
int parent[1001];
int height[1001];


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
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", &cities[i][0]);

        parent[i] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int w = 1;
            for (int l = 0; l < m; ++l)
            {
                if (cities[i][l] != cities[j][l])
                {
                    w = 0;
                    break;
                }
            }

            if (w == 0)
            {
                w = m;
                for (int l = m; l < k; ++l)
                {
                    w += (cities[i][l] != cities[j][l]);
                }
            }

            edges[eCnt++] = {i, j, w};
        }
    }

    std::sort(edges, edges + eCnt);

    int total = 0LL;
    for (int i = 0; i < eCnt && n != 1; ++i)
    {
        int ra = findSet(edges[i].a), rb = findSet(edges[i].b);
        if (ra != rb)
        {
            --n;
            unionSets(ra, rb);
            total += edges[i].weight;
        }
    }

    printf("%d", total);

    return 0;
}