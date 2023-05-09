#include <algorithm>


const int MAX_ITEMS = 100000;

int parent[MAX_ITEMS];
int size[MAX_ITEMS];

void makeSet(int v)
{
    parent[v] = v;
    size[v] = 1;
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
    if (size[v] > size[u])
    {
        std::swap(u, v);
    }
    parent[v] = u;
    size[u] += size[v];
}