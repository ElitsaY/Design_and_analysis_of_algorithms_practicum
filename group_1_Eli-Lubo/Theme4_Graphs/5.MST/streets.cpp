/**
 * @author Lyuben Georgiev
 * @brief Problem И пак пътища :): https://judge.openfmi.net/practice/open_contest?contest_id=79
 * @date 11/05/2023
 * 
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

struct Edge
{
    std::string a;
    std::string b;
    int weight;

    bool operator <(const Edge &other)
    {
        return weight < other.weight;
    }
};

int n, m, k;
Edge edges[100001];
std::unordered_map<std::string, std::string> parent;
std::unordered_map<std::string, int> height;


std::string findSet(const std::string &v)
{
    if (v == parent[v])
    {
        return v;
    }

    return parent[v] = findSet(parent[v]);
}

void unionSets(std::string &u, std::string &v)
{
    int hv = height[v];
    int hu = height[u];
    if (hv > hu)
    {
        std::swap(u, v);
    }
    else if (hv == hu)
    {
        ++height[u];
    }
    parent[v] = parent[u];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    std::string a, b;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
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

        std::string ra = findSet(a), rb = findSet(b);
        if (ra != rb)
        {
            --n;
            unionSets(ra, rb);
        }
    }

    for (int i = 0; i < k; ++i)
    {
        std::cin >> edges[i].a >> edges[i].b >> edges[i].weight;
        const auto &[a, b, w] = edges[i];
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
    }

    std::sort(edges, edges + k);

    long long needed = 0LL;
    for (int i = 0; i < k && n != 1; ++i)
    {
        std::string ra = findSet(edges[i].a), rb = findSet(edges[i].b);
        if (ra != rb)
        {
            --n;
            unionSets(ra, rb);
            needed += (long long)edges[i].weight;
        }
    }

    std::cout << needed;

    return 0;
}