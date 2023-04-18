#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 1e5;

int V;
int u, v;

bool used[MAXN + 5], color[MAXN + 5];
vector <int> adj[MAXN + 5];

int colorCnt[2];
void DFS(int x, bool c)
{
    color[x] = c;
    used[x] = true;

    colorCnt[c]++;
    for (int y : adj[x])
    {
        if(!used[y])
        {
            DFS(y, c^1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V;
    for (int i = 0; i < V - 1; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 0);

    cout << colorCnt[0] * 1LL * colorCnt[1] - (V - 1) << '\n';
}
