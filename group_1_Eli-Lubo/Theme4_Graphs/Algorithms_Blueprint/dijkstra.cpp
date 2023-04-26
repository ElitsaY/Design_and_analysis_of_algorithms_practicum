#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 1000000000

using Pair = std::pair<int, int>;


const int MAX_VERTICES = 100000;
const int SOURCE = 1;

int n, m;
std::vector<Pair> adjList[MAX_VERTICES + 1];
int dist[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];
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
        adjList[u].push_back({v, w});
    }

    std::fill(dist, dist + n + 1, INF);
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, SOURCE});
    dist[SOURCE] = 0;

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (const Pair &p : adjList[u])
        {
            int v = p.first;
            int weight = p.second;
            if (!visited[v] && curDist + weight < dist[v])
            {
                dist[v] = curDist + weight;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
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
    for (int i = path.size() - 1; i > 0; --i)
    {
        printf("%d -> ", path[i]);
    }
    printf("%d\n", path[0]);

    return 0;
}
/*
5 6
1 2 17
1 4 3
2 3 8
4 3 18
4 5 33
3 5 15
*/