/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/122
 * @date 04/05/2023
 * 
*/

#include <cstdio>
#include <unordered_map>
#include <queue>

using Pair = std::pair<int, int>;

int n, m;
std::unordered_map<int, int> adjList[20001];
bool visited[20001];


int main()
{
    scanf("%d%d", &n, &m);

    int from, to, cost;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &from, &to, &cost);

        if (from == to) { continue; }

        if (adjList[from].find(to) != adjList[from].end())
        {
            adjList[from][to] = std::min(adjList[from][to], cost);
            adjList[to][from] = std::min(adjList[to][from], cost);
        }
        else
        {
            adjList[from][to] = cost;
            adjList[to][from] = cost;
        }
    }

    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, 1});

    int res = 0;
    while (!pq.empty())
    {
        const auto [curCost, cur] = pq.top();
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;
        res += curCost;

        for (const auto [to, price] : adjList[cur])
        {
            if (!visited[to])
            {
                pq.push({price, to});
            }
        }
    }
    
    printf("%d", res);

    return 0;
}