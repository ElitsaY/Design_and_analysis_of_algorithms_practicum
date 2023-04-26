#include <iostream>
#include <vector>
#include <queue>9

using namespace std;

const int MAXN = 1e6;
const int64_t inf = 1e9;
using DijkstraPriorityQueue = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

int n;
int dist[MAXN + 5];
vector<pair<int, int>> adj[MAXN + 5];

void useVertex(int x, DijkstraPriorityQueue& pq)
{
    for (pair<int, int> &e : adj[x])
    {
        if (dist[e.first] > dist[x] + e.second)
        {
            dist[e.first] = dist[x] + e.second;
            pq.emplace(dist[e.first], e.first);
        }
    }
}

void Dijkstra()
{
    for (int x = 1; x <= MAXN; x++)
    {
        dist[x] = inf;
    }

    DijkstraPriorityQueue pq;
    pq.emplace(0, 1);
    dist[1] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[x] != d)
        {
            continue;
        }

        useVertex(x, pq);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int U, D, I, J, L;
    cin >> n >> U >> D >> I >> J >> L;

    for (int i = 2; i <= MAXN; i++)
    {
        adj[i - 1].emplace_back(i, U);
        adj[i].emplace_back(i - 1, D);
    }

    for (int i = 0; i < L; i++)
    {
        int k;
        cin >> k;

        vector<int> floors(k);
        for (int j = 0; j < k; j++)
        {
            cin >> floors[j];
            for (int p = 0; p < j; p++)
            {
                adj[floors[p]].emplace_back(floors[j], I + J);
                adj[floors[j]].emplace_back(floors[p], I + J);
            }
        }
    }

    Dijkstra();
    cout << dist[n] << '\n';
}
/*
10 1 1 1 1 1
2 3 7
*/
