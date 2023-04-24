#include <cstdio>
#include <vector>


const int MAX_VERTICES = 100000;
const int SOURCE = 1;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool visited[100000 + 1];


void dfs(int u)
{
    // Mark the current vertex as visited
    visited[u] = true;
    printf("%d ", u); // Print the dfs traversal

    // Traverse all adjecent to U vertices
    for (int v : adjList[u])
    {
        // Go recursively in V if it is NOT visited
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

    // Start dfs from SOURCE
    // Note if the graph is NOT connected you might need multiple calls to dfs to traverse the whole graph like:
    // for (int u = 1; u <= n; ++u)
    // {
    //     if (!visited[u])
    //     {
    //         dfs(u);
    //     }
    // }
    dfs(SOURCE);

    printf("\n");

    return 0;
}