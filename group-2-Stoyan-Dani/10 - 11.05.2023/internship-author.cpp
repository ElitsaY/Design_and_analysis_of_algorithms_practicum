#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

const long long INF=1e18;
const int MAX_N=5e5;
const int MAX_M=1e7+2;

struct Interval
{
    int from;
    int to;
    long long cost;
};
struct Edge
{
    int to;
    long long cost;
};
Interval is[MAX_N];
std::vector<Edge> es[MAX_M];
long long cost[MAX_M];
int eventList[MAX_N*2+2];
int a,b;
int n;
long long ans;
int maxCoord;

void input()
{
    std::cin>>n;
    std::cin>>a>>b;
    ++b;
    maxCoord=b;
    for (int i=0;i<n;++i)
    {
        std::cin>>is[i].from>>is[i].to>>is[i].cost;
        ++is[i].to;
        if (is[i].to>maxCoord) maxCoord=is[i].to;
    }
}
void output()
{
    if (ans<INF) std::cout<<ans<<'\n';
    else std::cout<<"Impossible\n";
}
void build_forward_edges()
{
    for (int i=0;i<n;++i)
    {
        es[is[i].from].push_back({is[i].to,is[i].cost});
    }
}
void build_back_edges()
{
    for (int i=0;i<n;++i)
    {
        eventList[2*i]=is[i].from;
        eventList[2*i+1]=is[i].to;
    }
    eventList[2*n]=a;
    eventList[2*n+1]=b;
    std::sort(eventList,eventList+2*n+2);
    for (int i=1;i<2*n+2;++i)
    {
        if (eventList[i]!=eventList[i-1])
        {
            es[eventList[i]].push_back({eventList[i-1],0});
        }
    }
}
void dijkstra()
{
    std::priority_queue<std::pair<long long, int>> q;
    cost[a]=0;
    q.push({cost[a],a});
    int curr;
    while (!q.empty())
    {
        curr=q.top().second;
        q.pop();
        for (int i=0;i<es[curr].size();++i)
        {
            const Edge& e=es[curr][i];
            if (cost[curr]+e.cost<cost[e.to])
            {
                cost[e.to]=cost[curr]+e.cost;
                q.push({-cost[e.to],e.to});
            }
        }
    }
}
void solve()
{
    std::fill(cost,cost+maxCoord+1,INF);
    build_forward_edges();
    build_back_edges();
    dijkstra();
    ans=cost[b];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    input();
    solve();
    output();
    return 0;
}

