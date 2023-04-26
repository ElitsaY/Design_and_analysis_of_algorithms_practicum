#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 5;

int n;
int c[MAXN];
vector <pair <int, pair <int, int>>> deals;

using InvertedPriorityQueue = priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>>;
vector <pair <int, pair <int, int>>> productToDeals[MAXN];

void useProduct(int x, InvertedPriorityQueue &pq)
{
    for(auto &deal: productToDeals[x])
    {
        if(c[deal.first] > c[deal.second.first] + c[deal.second.second])
        {
            c[deal.first] = c[deal.second.first] + c[deal.second.second];
            pq.push({c[deal.first], deal.first});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++) cin >> c[i];

    for(int i = 0;i<m;i++)
    {
        int a, x, y;
        cin >> a >> x >> y;

        deals.push_back({a, {x, y}});
        productToDeals[x].push_back(deals.back());
        productToDeals[y].push_back(deals.back());
    }

    InvertedPriorityQueue pq;
    for(int i = 1;i<=n;i++)
        pq.push({c[i], i});

    while(pq.empty()==false)
    {
        pair <int, int> x = pq.top();
        pq.pop();

        if(x.second==1) break;

        if(x.first!=c[x.second]) continue;
        useProduct(x.second, pq);
    }

    cout << c[1] << '\n';
}
/*
5 3
5 0 1 2 5
5 2 3
4 2 3
1 4 5

3 1
2 2 1
1 2 3
*/
