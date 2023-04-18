#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5;

int n, m, v;
vector <int> adj[MAXN + 5];

int dist[MAXN + 5];

void bfs()
{
    for (int x = 1; x <= n; x++)
    {
        dist[x] = -1;
    }

    queue<int> q;
    dist[v] = 0;
    q.push(v);

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int y: adj[x])
        {
            if (dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    bfs();

    cout << dist[1];
    for (int x = 2; x <= n; x++)
    {
        cout << " " << dist[x];
    }
}
