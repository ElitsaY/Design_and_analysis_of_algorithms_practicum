/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/151
 * @date 27/04/2023
 * 
*/

#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>


using Pair = std::pair<int, int>;

const int INF = 1000000000;
const int MAX_VERTICES = 100000;
const int SOURCE = 1;

struct Destination
{
    int to;
    int price;
    int time;
};

int n, m, k;
std::vector<Destination> adjList[MAX_VERTICES + 1];
int times[MAX_VERTICES + 1];
bool visited[MAX_VERTICES + 1];

bool reachable(int maxTicket)
{
    std::fill(times, times + n + 1, INF);
    std::fill(visited, visited + n + 1, false);

    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, SOURCE});
    times[SOURCE] = 0;

    while (!pq.empty())
    {
        int curTime = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (const Destination &d : adjList[u])
        {
            int v = d.to;
            int vprice = d.price;
            int vtime = d.time;
            if (vprice <= maxTicket && !visited[v] && curTime + vtime < times[v])
            {
                times[v] = curTime + vtime;
                pq.push({times[v], v});
            }
        }
    }

    return times[n] <= k;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int a, b, p, t;
        scanf("%d %d %d %d", &a, &b, &p, &t);
        adjList[a].push_back({b, p, t});
    }

    int l = 1, r = 1000000;
    while (l <= r)
    {
        int m = l + (r-l) / 2;
        if (reachable(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    if (r == 1000000)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", l);
    }

    return 0;
}