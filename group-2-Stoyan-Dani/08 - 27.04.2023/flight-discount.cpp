#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State
{
    int x;
    bool hasUsed;

    State(){}
    State(int x, bool hasUsed) : x(x), hasUsed(hasUsed) {}
};

bool operator <(const State &A, const State &B)
{
    if (A.x != B.x)
    {
        return A.x < B.x;
    }

    return A.hasUsed < B.hasUsed;
}

const int MAXN = 1e5;
const int64_t inf = 1e17;
using DijkstraPriorityQueue = priority_queue<pair<int64_t, State>, vector<pair<int64_t, State>>, greater<pair<int64_t, State>>>;

int n;
int64_t dist[MAXN + 5][2];
vector<pair<int, int64_t>> adj[MAXN + 5];

void useVertex(int x, bool hasUsed, DijkstraPriorityQueue& pq)
{
    for (pair<int, int64_t> &e : adj[x])
    {
        if (dist[e.first][hasUsed] > dist[x][hasUsed] + e.second)
        {
            dist[e.first][hasUsed] = dist[x][hasUsed] + e.second;
            pq.emplace(dist[e.first][hasUsed], State(e.first, hasUsed));
        }
        if (!hasUsed)
        {
            if (dist[e.first][true] > dist[x][false] + e.second / 2)
            {
                dist[e.first][true] = dist[x][false] + e.second / 2;
                pq.emplace(dist[e.first][true], State(e.first, true));
            }
        }
    }
}

void Dijkstra()
{
    for (int x = 1; x <= n; x++)
    {
        dist[x][false] = dist[x][true] = inf;
    }

    DijkstraPriorityQueue pq;
    pq.emplace(0, State(1, false));
    dist[1][false] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second.x;
        bool hasUsed = pq.top().second.hasUsed;
        int64_t d = pq.top().first;
        pq.pop();

        if (dist[x][hasUsed] != d)
        {
            continue;
        }

        useVertex(x, hasUsed, pq);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].emplace_back(y, w);
    }

    Dijkstra();
    cout << min(dist[n][false], dist[n][true]) << '\n';
}
