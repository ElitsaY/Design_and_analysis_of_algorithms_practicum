/**
 * @author Lyuben Georgiev
 * @brief Problem: https://arena.olimpiici.com/#/catalog/186/problem/100443
 * @date 27/04/2023
 * 
*/

#include <cstdio>
#include <vector>
#include <unordered_map>


const int MAX_VERTICES = 2e5 + 7;

int n, m;
std::unordered_map<int, int> mapping;
std::vector<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];

void dfs(int u)
{
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int idx = 1;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        if (!mapping[a])
        {
            mapping[a] = idx++;
        }
        if (!mapping[b])
        {
            mapping[b] = idx++;
        }

        adjList[mapping[a]].push_back(mapping[b]);
        adjList[mapping[b]].push_back(mapping[a]);
    }

    int components = 0;
    for (int i = 1; i < idx; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", n - idx + 1 + components);

    return 0;
}
