/**
 * @author Lyuben Georgiev
 * @brief Problem President: https://judge.openfmi.net/practice/open_contest?contest_id=149
 * @date 11/05/2023
 * 
*/

#include <cstdio>
#include <algorithm>

struct Edge
{
    long long a : 21;
    long long b : 21;
    long long weight : 21;
};

int n, m;
long long k;
Edge edges[1000001];
int parent[1000001];
int height[1000001];

void makeSets()
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
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
    scanf("%d %d %lld", &n, &m, &k);
    
    makeSets();

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    std::sort(edges, edges + m, [](const Edge &e1, const Edge &e2){
        return e1.weight < e2.weight;
    });

    int components = n, res = (n - 1 <= k) ? n - 1 : -1;
    long long total = 0LL;
    for (int i = 0; i < m && components != 1; ++i)
    {
        int ra = findSet(edges[i].a), rb = findSet(edges[i].b);
        if (ra != rb)
        {
            --components;
            unionSets(ra, rb);
            total += edges[i].weight;
            if (total + components - 1LL <= k)
            {
                res = components - 1;
            }
        }
    }

    printf("%d", components == 1 ? res : -1);

    return 0;
}