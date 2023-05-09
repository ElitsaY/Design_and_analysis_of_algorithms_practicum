#include <algorithm>


const int MAX_ITEMS = 100000;

int parent[MAX_ITEMS];
int height[MAX_ITEMS];

void makeSet(int v)
{
    parent[v] = v;
    height[v] = 0;
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