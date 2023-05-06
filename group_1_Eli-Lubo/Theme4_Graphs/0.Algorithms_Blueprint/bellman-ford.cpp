#include <cstdio>
#include <algorithm>
#include <vector>

#define INF 1000000000


const int MAX_VERTICES = 1000;
const int SOURCE = 1;

struct Edge
{
    int from;
    int to;
    int weight;
};

int n, m;
std::vector<Edge> edgeList;
int dist[MAX_VERTICES + 1];
int parent[MAX_VERTICES + 1];

void printSolution()
{
    printf("\nVertex \t\t Distance from Source\n");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
    printf("\n");
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edgeList.push_back({u, v, w});
    }

    std::fill(dist, dist + n + 1, INF);
    dist[SOURCE] = 0;

    for (int i = 0; i < n-1; ++i)
    {
        for (const Edge &e : edgeList)
        {
            if (dist[e.from] + e.weight < dist[e.to])
            {
                dist[e.to] = dist[e.from] + e.weight;
                parent[e.to] = e.from;
            }
        }
    }

    bool negativeCycle = false;
    for (const Edge &e : edgeList)
    {
        if (dist[e.from] + e.weight < dist[e.to])
        {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle)
    {
        printf("The graph contains negative length cycle reachable from SOURCE vertex\n");

        return 0;
    }

    printSolution();

    // Let's print the shortest path from source to destination (if it exists)
    const int DESTINATION = n;
    if (dist[n] == INF)
    {
        printf("There is no path from %d to %d\n", SOURCE, DESTINATION);

        return 0;
    }

    std::vector<int> path;
    int current = DESTINATION;
    while (current != 1)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(current);

    // Iterate the path backwards
    printf("Shortest path from SOURCE to DESTINATION:\n");
    for (int i = path.size() - 1; i > 0; --i)
    {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]);

    return 0;
}
/*
No negative length cycle:
5 6
1 2 17
1 4 3
2 3 8
4 3 18
4 5 33
3 5 15

Negative length cycle:
4 4
1 2 1
2 3 -1
3 4 -1
4 1 -1
*/