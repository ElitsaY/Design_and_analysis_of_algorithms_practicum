#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

int n;
string names[MAXN + 5];
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

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    for (int i = 1; i < n; i++)
    {
        int equalCnt = 0;
        while (equalCnt < names[i - 1].size() && equalCnt < names[i].size()
               && names[i - 1][equalCnt] == names[i][equalCnt])
        {
            equalCnt++;
        }

        if (equalCnt < names[i - 1].size() && equalCnt < names[i].size())
        {
            adj[names[i - 1][equalCnt] - 'a'].push_back(names[i][equalCnt] - 'a');
        }

        if (equalCnt == names[i].size() && equalCnt < names[i - 1].size())
        {
            cout << "Impossible" << '\n';
            return 0;
        }
    }

    for (int x = 1; x <= n; x++)
    {
        sort(adj[x].begin(), adj[x].end(), greater<int>());
    }

    for (int x = 'a'; x <= 'z'; x++)
    {
        if (!used[x - 'a'])
        {
            dfs(x - 'a');
        }
    }

    for (int x = 'a'; x <= 'z'; x++)
    {
        for (int y : adj[x - 'a'])
        {
            if (nodePos[y] > nodePos[x - 'a'])
            {
                cout << "Impossible" << '\n';
                return 0;
            }
        }
    }

    reverse(topsort.begin(), topsort.end());

    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << char(topsort[i - 'a'] + 'a');
    }
    cout << '\n';
}
