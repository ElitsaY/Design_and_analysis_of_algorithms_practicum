#include <cstdio>
#include <vector>
#include <queue>


const int MAX_VERTICES = 100000;
const int SOURCE = 1;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool used[100000 + 1];


void bfs(int source)
{
    // Add source vertex to the queue
    std::queue<int> q;
    q.push(source);

    // Mark the source vertex as used
    used[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        printf("%d ", u); // Print the bfs traversal

        // Traverse all adjecent to U vertices
        for (int v : adjList[u])
        {
            // Add V to the queue if it is NOT used
            if (!used[v])
            {
                q.push(v);
                used[v] = true;
            }
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
    }

    // Start bfs from SOURCE
    bfs(SOURCE);
    printf("\n");

    // Note if the graph is NOT connected you might need multiple calls to bfs to traverse the whole graph like:
    // for (int u = 1; u <= n; ++u)
    // {
    //     if (!visited[u])
    //     {
    //         bfs(u);
    //     }
    // }

    return 0;
}