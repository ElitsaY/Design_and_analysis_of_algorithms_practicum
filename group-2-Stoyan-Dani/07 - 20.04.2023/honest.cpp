#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5;

int n, m;
vector <pair <int, bool>> graph[MAXN + 5];

bool used[MAXN + 5];
void dfs(int x, int col, int colCnt[])
{
    used[x] = true;
    colCnt[col]++;

    for(pair <int, bool> &e: graph[x])
    {
        if(used[e.first]==false)
        {
            dfs(e.first, col ^ e.second, colCnt);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0;i<m;i++)
    {
        char c;
        int x, y;
        cin >> x >> c >> y;

        if(c=='h')
        {
            graph[x].emplace_back(y, false);
            graph[y].emplace_back(x, false);
        }
        else
        {
            graph[x].emplace_back(y, true);
            graph[y].emplace_back(x, true);
        }
    }

    int ans = 0;
    for(int x = 1;x<=n;x++)
    {
        if(used[x]==true) continue;

        int colCnt[2] = {0, 0};
        dfs(x, 0, colCnt);

        ans += max(colCnt[0], colCnt[1]);
    }

    cout << ans << '\n';
}
/*
5 9
1 h 2
2 h 3
1 l 4
2 l 4
5 h 4
3 l 4
1 l 5
2 l 5
5 l 3
*/

