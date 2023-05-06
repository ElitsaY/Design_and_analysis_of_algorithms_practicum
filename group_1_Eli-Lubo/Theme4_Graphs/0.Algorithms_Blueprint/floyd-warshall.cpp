#include <cstdio>
#include <algorithm>

#define INF 1000000000


const int MAX_VERTICES = 100;
const int SOURCE = 1;

int n, m;
int dist[MAX_VERTICES + 1][MAX_VERTICES + 1];


int main()
{
    for (int i = 0; i <= MAX_VERTICES; ++i)
    {
        std::fill(&dist[i][0], &dist[i][0] + MAX_VERTICES, INF);
        dist[i][i] = 0;
    }

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        dist[u][v] = std::min(dist[u][v], w); // There might be multiple edges from U to V

    }

    for (int through = 1; through <= n; ++through)
    {
        for (int from = 1; from <= n; ++from)
        {
            for (int to = 1; to <= n; ++to)
            {
                if (dist[from][through] + dist[through][to] < dist[from][to])
                {
                    dist[from][to] = dist[from][through] + dist[through][to];
                }
            }
        }
    }

    for (int destination = 1; destination <= n; ++destination)
    {
        printf("%d ", dist[SOURCE][destination]);
    }
    printf("\n");

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