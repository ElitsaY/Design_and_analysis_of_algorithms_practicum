/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/114
 * @date 27/04/2023
 * 
*/

#include <cstdio>
#include <deque>
#include <vector>


const int INF = 1000000000;

int n, m, k;

struct Edge
{
    int to;
    int weight;
};

std::vector<Edge> adjList[10001];
bool visited[10001];
int costs[10001];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    int from, to;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &from, &to);

        adjList[from].push_back({to, 0});
        adjList[to].push_back({from, 0});
    }

    for (int i = 0; i < k; ++i)
    {
        scanf("%d%d", &from, &to);

        adjList[from].push_back({to, 1});
        adjList[to].push_back({from, 1});
    }

    std::fill(costs, costs + n + 1, INF);
    costs[1] = 0;

    std::deque<int> dq;
    dq.push_back(1);

    while (!dq.empty())
    {
        int cur = dq.front();
        dq.pop_front();

        visited[cur] = true;

        for (const auto [to, dangerous] : adjList[cur])
        {
            if (visited[to])
            {
                continue;
            }

            if (dangerous)
            {
                dq.push_back(to);
            }
            else
            {
                dq.push_front(to);
            }
            costs[to] = std::min(costs[to], costs[cur] + dangerous);
        }
    }

    printf("%d", costs[n] == INF ? -1 : costs[n]);

    return 0;
}