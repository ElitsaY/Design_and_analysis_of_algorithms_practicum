#include <cstdio>
#include <vector>
#include <queue>


const int MAX_VERTICES = 100000;
const int SOURCE = 1;

int n, m;
std::vector<int> adjList[MAX_VERTICES + 1];
bool used[100000 + 1];
std::vector<std::vector<int>> levels;


void levelBfs(int source)
{
    // Add source vertex to the queue
    std::queue<int> q;
    q.push(source);

    // Mark the source vertex as used
    used[source] = true;

    // Add empty vector for level 0
    levels.push_back({});

    // The current level we are on
    int level = 0;

    // Remaining elements of the current level
    int remaining = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        --remaining; // Decrease remaining vertices on current level
        
        levels[level].push_back(u);

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

        if (remaining == 0)
        {
            ++level;
            remaining = q.size();

            if (remaining)
                levels.push_back({});
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

    // Start levelBfs from SOURCE
    levelBfs(SOURCE);

    for (int i = 0; i < levels.size(); ++i)
    {
        printf("Level %d: ", i);
        for (int vertex : levels[i])
        {
            printf("%d ", vertex);
        }
        printf("\n");
    }

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