#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5;
using PrimPQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

int n, m;
vector<pair<int, int>> adj[MAXN + 5];

bool inTree[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    PrimPQ pq;
    pq.emplace(0, 1);

    int64_t ans = 0;
    int addedNodes = 0;

    while(!pq.empty())
    {
        int x = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (inTree[x])
        {
            continue;
        }

        ans += w;
        addedNodes++;
        inTree[x] = true;

        for (const pair<int, int> &e : adj[x])
        {
            if (!inTree[e.first])
            {
                pq.emplace(e.second, e.first);
            }
        }
    }

    if (addedNodes != n)
    {
        cout << "IMPOSSIBLE" << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
