/**
 * @author Lyuben Georgiev
 * @brief Problem: https://arena.olimpiici.com/#/catalog/756/problem/101958
 * @date 27/04/2023
 * 
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

struct Dest
{
    int to;
    long long s;
    long long g;
    long long r;
};

using Pair = std::pair<long long, int>;

const long long int INF = 1e16;
const int SOURCE = 1;

int n, m;
long long s;
std::vector<Dest> adjList[100001];
bool visited[100001];
long long dist[100001];

int main()
{
    scanf("%d %d %lld", &n, &m, &s);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        long long s, g, r;
        scanf("%d %d %lld %lld %lld", &a, &b, &s, &g, &r);

        adjList[a].push_back({b, s, g, r});
        adjList[b].push_back({a, s, g, r});
    }

    std::fill(dist, dist + n + 1, INF);
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({s, SOURCE});

    while (!pq.empty())
    {
        auto [curTime, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (const auto &[v, si, gi, ri] : adjList[u])
        {
            long long waitTime = (curTime % (gi + ri));
            if (waitTime >= gi)
            {
                waitTime = gi + ri - waitTime;
            }
            else
            {
                waitTime = 0;
            }

            if (!visited[v] && curTime + waitTime + si < dist[v])
            {
                dist[v] = curTime + waitTime + si;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 2; i <= n; ++i)
    {
        printf("%lld ", dist[i]);
    }

    return 0;
}