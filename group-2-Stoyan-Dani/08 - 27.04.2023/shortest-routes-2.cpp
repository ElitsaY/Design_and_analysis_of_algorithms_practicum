#include <iostream>

using namespace std;

const int MAXN = 500;
const int64_t inf = 1e17;

int n;
int64_t dist[MAXN + 5][MAXN + 5];

void computeShortestPaths()
{
    for (int k = 1; k <= n; k++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                if (dist[a][b] > dist[a][k] + dist[k][b])
                {
                    dist[a][b] = dist[a][k] + dist[k][b];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, Q;
    cin >> n >> m >> Q;

    for (int x = 1; x <= n; x++)
    {
        for (int y = x + 1; y <= n; y++)
        {
            dist[x][y] = dist[y][x] = inf;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        dist[x][y] = min(dist[x][y], (int64_t) w);
        dist[y][x] = min(dist[y][x], (int64_t) w);
    }

    computeShortestPaths();

    while (Q--)
    {
        int x, y;
        cin >> x >> y;

        cout << ((dist[x][y] == inf) ? -1 : dist[x][y]) << '\n';
    }
}
