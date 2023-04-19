#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e4;

int n;
vector<int> adj[MAXN + 5];

bool used[MAXN + 5];
vector<int> topsort;
int nodePos[MAXN + 5];

void dfs(int x)
{
    used[x] = true;

    for (int y : adj[x])
    {
        if (!used[y])
        {
            dfs(y);
        }
    }

    nodePos[x] = topsort.size();
    topsort.push_back(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    for (int x = 1; x <= n; x++)
    {
        sort(adj[x].begin(), adj[x].end(), greater<int>());
    }

    for (int x = n; x >= 1; x--)
    {
        if (!used[x])
        {
            dfs(x);
        }
    }

    for (int x = 1; x <= n; x++)
    {
        for (int y : adj[x])
        {
            if (nodePos[y] > nodePos[x])
            {
                cout << "Sandro fails." << '\n';
                return 0;
            }
        }
    }

    reverse(topsort.begin(), topsort.end());

    cout << topsort[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << topsort[i];
    }
    cout << '\n';
}
