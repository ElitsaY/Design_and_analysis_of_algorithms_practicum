#include <cstdio>
#include <vector>


const int MAX_VERTICES = 100000;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool visited[100000 + 1];


void dfs(int u)
{
    visited[u] = true;
    printf("%d ", u); // Print the dfs traversal

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
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    for (int u = 1; u <= n; ++u)
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
    printf("\n");

    return 0;
}