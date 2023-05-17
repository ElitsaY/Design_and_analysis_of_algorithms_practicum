/**
 * @author Lyuben Georgiev
 * @brief Problem: https://arena.olimpiici.com/#/catalog/186/problem/100443
 * @date 17/05/2023
 * 
*/

#include <cstdio>
#include <unordered_map>
#include <algorithm>

int n, m;
std::unordered_map<int, int> parent;
std::unordered_map<int, int> height;

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
        int a, b;
        scanf("%d %d", &a, &b);

        if (parent.count(a) == 0)
        {
            parent[a] = a;
            height[a] = 0;
        }
        if (parent.count(b) == 0)
        {
            parent[b] = b;
            height[b] = 0;
        }

        int ra = findSet(a);
        int rb = findSet(b);
        if (ra != rb)
        {
            unionSets(ra, rb);
            --n;
        }
    }

    printf("%d", n);

    return 0;
}