#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500;

bool inTree[MAXN*2+5];
int edgeCost[MAXN*2+5];
vector <pair <int, int>> graph[MAXN*2+5];

void update(int x)
{
    inTree[x] = true;
    for(auto e: graph[x])
    {
        edgeCost[e.first] = max(edgeCost[e.first], e.second);
    }
}

int getBestNode(int n)
{
    int ans = -1;
    for(int x = 0;x<n;x++)
    {
        if(inTree[x]==false && edgeCost[x]!=-1 && (ans==-1 || edgeCost[x]>edgeCost[ans]))
            ans = x;
    }

    return ans;
}

int64_t MSF(int n) //maximum spanning forest
                   //Prim's algorithm
{
    for(int x = 0;x<n;x++)
    {
        inTree[x] = false;
        edgeCost[x] = -1;
    }

    int64_t ans = 0;

    while(true)
    {
        int start = -1;
        for(int x = 0;x<n;x++)
        {
            if(inTree[x]==false)
            {
                start = x;
                break;
            }
        }
        if(start==-1) break;

        update(start);
        while(true)
        {
            int x = getBestNode(n);
            if(x==-1) break;

            ans += edgeCost[x];
            update(x);
        }
    }


    return ans;
}

void solveTestcase(int testcase)
{
    int n;
    cin >> n;

    for(int x = 0;x<=2*n;x++)
        graph[x].clear();

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int trash;
            cin >> trash;
        }
    }

    int64_t costSum = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int b;
            cin >> b;

            if(b!=0)
            {
                costSum += b;
                graph[i].push_back({j+n, b});
                graph[j+n].push_back({i, b});
            }
        }
    }

    for(int i = 0;i<n;i++)
    {
        int trash;
        cin >> trash;
    }
    for(int i = 0;i<n;i++)
    {
        int trash;
        cin >> trash;
    }

    cout << "Case #" << testcase << ": " << costSum - MSF(2*n) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int t = 1;t<=T;t++)
        solveTestcase(t);
}
