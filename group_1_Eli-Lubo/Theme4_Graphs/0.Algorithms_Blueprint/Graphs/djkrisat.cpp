#include <cstdio>
#include <vector>
#include <algorithm>

using Pair = std::pair<int, int>;

const long long INF = 1e12;

struct Dest
{
    int to;
    int price;
    int time;
};


int n, m, k;
std::vector<Dest> adjList[100001];
long long dist[100001];
bool visited[100001];

bool good(int maxTicket)
{
    std::fill(dist, dist + 100001, INF);
    std::fill(visited, visited + 100001, false);



    return dist[n] <= k;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i)
    {
        int from, to, price, time;
        scanf("%d %d %d %d", &from, &to, &price, &time);
        adjList[from].push_back({to, price, time});
    }

    int l = 1, r = 1000000;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (good(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d", l == 1000000 + 1 ? -1 : l);

    return 0;
}