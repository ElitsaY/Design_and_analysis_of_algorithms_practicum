#include <bits/stdc++.h>

using namespace std;

#define MAX 101000

#define PA pair<long long, long long>

long long n, m, a, b, c, dist[MAX * 2];

bool used[MAX * 2];

vector<PA> graph[MAX * 2];

long long encode(int v, int fl)
{
    return n * fl + v;
}

void dijkstra(int from)
{
    int node;
    fill(dist, dist + 2 * n + 2, LLONG_MAX / 2);
    priority_queue<PA, vector<PA>, greater<PA> > pq;
    dist[from] = 0;
    pq.push({0, from});
    while(!pq.empty())
    {
        node = pq.top().second;
        pq.pop();
        if(used[node])continue;
        used[node] = true;
        for(int i = 0; i < graph[node].size(); i++)
        {
            if(dist[graph[node][i].first] > dist[node] + graph[node][i].second)
            {
                dist[graph[node][i].first] = dist[node] + graph[node][i].second;
                pq.push({dist[graph[node][i].first], graph[node][i].first});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        if(a > b)swap(a, b);
        graph[encode(a, 0)].push_back({encode(b, 1), c});
        graph[encode(b, 1)].push_back({encode(a, 0), c});
    }
    
    
    dijkstra(1);
    
    cout << min(dist[n], dist[2 * n]) << endl;
    return 0;
}
