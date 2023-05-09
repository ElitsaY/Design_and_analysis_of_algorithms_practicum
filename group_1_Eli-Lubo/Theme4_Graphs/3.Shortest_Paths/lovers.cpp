/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/100
 * @date 27/04/2023
 * 
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using Pair = std::pair<int, int>;

const int INF = 1000000000;
const int SOURCE = 1;

int n, m;
int times[10001];
std::vector<Pair> adjList[10001];
bool visited[10001];
int dist[10001];
int parent[10001];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &times[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v, t;
        scanf("%d %d %d", &u, &v, &t);

        adjList[u].push_back({v, t});
    }

    std::fill(dist, dist + n + 1, INF);
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, SOURCE});

    while (!pq.empty())
    {
        auto [curTime, u] = pq.top();
        pq.pop();

        visited[u] = true;

        int waitTime = (times[u] - curTime % times[u]) % times[u];
        curTime += waitTime;
        for (const auto &[v, time] : adjList[u])
        {
            if (!visited[v] && curTime + time < dist[v])
            {
                dist[v] = curTime + time;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }

    if (dist[n] == INF)
    {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", dist[n]);

    std::vector<int> path;
    int current = n;
    while (current != SOURCE)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(SOURCE);

    std::reverse(path.begin(), path.end());

    printf("%d\n", path.size());
    for (int u : path)
    {
        printf("%d ", u);
    }

    return 0;
}