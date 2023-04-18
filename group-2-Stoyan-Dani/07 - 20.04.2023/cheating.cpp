#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

const int MAXN = 1e5;

struct AdjacentElement
{
    int x;
    bool type;

    AdjacentElement(){}
    AdjacentElement(int x, bool type) : x(x), type(type) {}
};

int n;
vector <AdjacentElement> adj[MAXN + 5];

int dist[MAXN + 5];
bool used[MAXN + 5];

void bfs01()
{
    for (int x = 1; x <= n; x++)
    {
        dist[x] = -1;
        used[x] = false;
    }

    deque<int> dq;
    dq.push_back(1);
    dist[1] = 0;

    while(!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();

        if (used[x])
        {
            continue;
        }
        used[x] = true;

        for (AdjacentElement y: adj[x])
        {
            if (dist[y.x] == -1 || dist[x] + ((y.type == false) ? 0 : 1) < dist[y.x])
            {
                if (y.type == false)
                {
                    dq.push_front(y.x);
                    dist[y.x] = dist[x];
                }
                else
                {
                    dq.push_back(y.x);
                    dist[y.x] = dist[x] + 1;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].emplace_back(y, false);
        adj[y].emplace_back(x, false);
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].emplace_back(y, true);
        adj[y].emplace_back(x, true);
    }

    bfs01();

    cout << dist[n] << '\n';
}
