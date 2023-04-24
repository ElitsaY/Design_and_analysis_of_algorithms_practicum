#include <cstdio>
#include <vector>
#include <algorithm>


const int MAX_VERTICES = 100000;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];
std::vector<int> stack;

void topSort(int u)
{
    // Mark the current vertex as visited
    visited[u] = true;

    // Traverse all adjecent to U vertices
    for (int v : adjList[u])
    {
        // Go recursively in V if it is NOT visited
        if (!visited[v])
        {
            topSort(v);
        }
    }

    // Add U on the stack
    stack.push_back(u);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        adjList[from].push_back(to);
    }

    for (int u = 1; u <= n; ++u)
    {
        if (!visited[u])
        {
            topSort(u);
        }
    }

    // Reverse the stack
    std::reverse(stack.begin(), stack.end());

    // Print the topological sort
    for (int u : stack)
    {
        printf("%d ", u);
    }
    printf("\n");

    return 0;
}
/*
4 4
2 1
3 1
4 2
4 3
*/