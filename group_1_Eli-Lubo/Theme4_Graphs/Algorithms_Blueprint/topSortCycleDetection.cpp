#include <cstdio>
#include <vector>
#include <algorithm>


const int MAX_VERTICES = 100000;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];
bool onCurPath[MAX_VERTICES + 1];
std::vector<int> stack;


bool topSortCycle(int u)
{
    if (onCurPath[u])
        return true;

    onCurPath[u] = true;
    for (int v : adjList[u])
    {
        if (!visited[v] && topSortCycle(v))
        {
            return true;
        }
    }
    
    visited[u] = true;
    onCurPath[u] = false;

    stack.push_back(u);

    return false;
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
        if (!visited[u] && topSortCycle(u))
        {
            printf("Cycle detected. The is not DAG\n");

            return 0;
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
4 5
2 1
3 1
4 2
4 3
1 4
*/