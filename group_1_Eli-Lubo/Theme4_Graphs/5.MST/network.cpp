/**
 * @author Lyuben Georgiev
 * @brief Problem Мрежа: https://judge.openfmi.net/practice/open_contest?contest_id=55
 * @date 10/05/2023
 * 
*/

#include <cstdio>
#include <vector>
#include <queue>

using Pair = std::pair<int, int>;

int n, m;
std::vector<Pair> adjList[10001];
bool visited[10001];


int main()
{
    scanf("%d%d", &n, &m);

    int from = 0, to = 0, cost = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &from, &to, &cost);

        adjList[from].push_back({to, cost});
        adjList[to].push_back({from, cost});
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