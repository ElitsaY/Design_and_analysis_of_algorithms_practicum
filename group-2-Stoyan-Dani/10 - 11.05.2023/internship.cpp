#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1e6;
const int64_t inf = 1e10;

using DijkstraPriorityQueue = priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>>;

struct Plan
{
    int s, e;
    int64_t cost;

    Plan() {}
    Plan(int s, int e, int64_t cost) : s(s), e(e), cost(cost) {}
};

int n;
int a, b;
Plan plans[MAXN + 5];

set<int> allMonths;
map<int, int> month2Code;

void compress()
{
    allMonths.insert(a);
    allMonths.insert(b);
    for (int i = 0; i < n; i++)
    {
        allMonths.insert(plans[i].s);
        allMonths.insert(plans[i].e);
    }

    int ind = 0;
    for (int  x : allMonths)
    {
        month2Code[x] = ind;
        ind++;
    }

    a = month2Code[a];
    b = month2Code[b];
    for (int i = 0; i < n; i++)
    {
        plans[i].s = month2Code[plans[i].s];
        plans[i].e = month2Code[plans[i].e];
    }
}

int64_t dist[MAXN * 2 + 5];
vector<pair<int, int64_t>> adj[MAXN * 2 + 5];

void buildGraph()
{
    for (int i = 0; i < n; i++)
    {
        adj[plans[i].s].emplace_back(plans[i].e, plans[i].cost);
    }

    int last = -1;
    for (int x : allMonths)
    {
        if (last != -1)
        {
            adj[month2Code[x]].emplace_back(month2Code[last], 0);
        }

        last = x;
    }
}

void useVertex(int x, DijkstraPriorityQueue& pq)
{
    for (pair<int, int64_t> &e : adj[x])
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
    for (int i = 0; i <= allMonths.size(); i++)
    {
        dist[i] = inf;
    }

    DijkstraPriorityQueue pq;
    pq.emplace(0, a);
    dist[a] = 0;

    while (!pq.empty())
    {
        int x = pq.top().second;
        int64_t d = pq.top().first;
        pq.pop();

        if (x >= b)
        {
            break;
        }

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

    cin >> n;
    cin >> a >> b;

    b++;
    for (int i = 0; i < n; i++)
    {
        cin >> plans[i].s >> plans[i].e >> plans[i].cost;
        plans[i].e++;
    }

    compress();
    buildGraph();
    Dijkstra();

    int64_t ans = inf;
    for (int i = b; i < allMonths.size(); i++)
    {
        ans = min(ans, dist[i]);
    }

    if (ans == inf)
    {
        cout << "Impossible" << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
/*
5
5 15
11 15 8
1 6 23
6 12 13
7 16 35
3 5 10
*/
