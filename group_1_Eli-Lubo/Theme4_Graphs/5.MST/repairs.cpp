/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/115
 * @date 10/05/2023
 * 
*/

#include <cstdio>
#include <vector>
#include <queue>

using Pair = std::pair<int, int>;

int n, m;
std::vector<Pair> adjList[20001];
bool visited[20001];


int main()
{
    scanf("%d %d", &n, &m);

    long long total = 0LL;
    for (int i = 0; i < m; ++i)
    {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);

        adjList[from].push_back({to, cost});
        adjList[to].push_back({from, cost});
        
        total += (long long)cost;
    }

    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, 1});

    long long res = 0LL;
    while (!pq.empty())
    {
        const auto [curCost, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;
        res += (long long)curCost;

        for (const auto [v, cost] : adjList[u])
        {
            if (!visited[v])
            {
                pq.push({cost, v});
            }

        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            printf("-1");

            return 0;
        }
    }
    
    printf("%lld", total - res);

    return 0;
}