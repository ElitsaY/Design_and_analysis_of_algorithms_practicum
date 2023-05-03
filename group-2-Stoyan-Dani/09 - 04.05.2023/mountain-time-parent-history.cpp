#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

const int MAXN = 1e3;
const array<pair<int, int>, 4> deltas = {make_pair(-1, 0), make_pair(+1, 0), make_pair(0, +1), make_pair(0, -1)};

struct ParentInfo
{
    pair<int, int> x;
    int height;

    ParentInfo(){}
    ParentInfo(const pair<int, int> &x, int height) : x(x), height(height) {}
};

int n, m;
int a[MAXN + 5][MAXN + 5];

bool isInside(const pair<int, int> &pos)
{
    return (0 <= pos.first && pos.first < n &&
            0 <= pos.second && pos.second < m);
}

int answer[MAXN + 5][MAXN + 5];

struct DSU
{
    int sz[MAXN + 5][MAXN + 5];
    int maxH[MAXN + 5][MAXN + 5];
    ParentInfo parent[MAXN + 5][MAXN + 5];
    list<pair<int, int>> highest[MAXN + 5][MAXN + 5];

    DSU() {}
    DSU(int n, int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sz[i][j] = 1;
                maxH[i][j] = a[i][j];
                highest[i][j].emplace_back(i, j);
                parent[i][j] = ParentInfo(make_pair(i, j), 0);
            }

        }
    }

    pair<int, int> Find(pair<int, int> x)
    {
        if (x == parent[x.first][x.second].x)
        {
            return x;
        }

        return Find(parent[x.first][x.second].x);
    }

    bool Union(pair<int, int> u, pair<int, int> v, int height)
    {
        u = Find(u);
        v = Find(v);
        if (u == v)
        {
            return false;
        }

        if (sz[u.first][u.second] < sz[v.first][v.second])
        {
            swap(u, v);
        }

        if (maxH[u.first][u.second] == maxH[v.first][v.second])
        {
            highest[u.first][u.second].splice(highest[u.first][u.second].begin(), highest[v.first][v.second]);
        }
        else if (maxH[u.first][u.second] < maxH[v.first][v.second])
        {
            for (const pair<int, int> &pos : highest[u.first][u.second])
            {
                answer[pos.first][pos.second] = a[pos.first][pos.second] - height;
            }

            highest[u.first][u.second].clear();
            highest[u.first][u.second].splice(highest[u.first][u.second].begin(), highest[v.first][v.second]);
        }
        else
        {
            for (const pair<int, int> &pos : highest[v.first][v.second])
            {
                answer[pos.first][pos.second] = a[pos.first][pos.second] - height;
            }
        }

        maxH[u.first][u.second] = max(maxH[u.first][u.second], maxH[v.first][v.second]);
        parent[v.first][v.second] = ParentInfo(u, height);
        sz[u.first][u.second] += sz[v.first][v.second];

        return true;
    }

    int getFirstReachOfHegiherPoint(pair<int, int> u, int h)
    {
        int lastH = -1;
        while (true)
        {
            if (maxH[u.first][u.second] > h) return lastH;

            lastH = parent[u.first][u.second].height;
            u = parent[u.first][u.second].x;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxHeight = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            maxHeight = max(maxHeight, a[i][j]);
        }
    }

    vector<pair<int, int>> cells;

    cells.reserve(n*m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cells.emplace_back(i, j);
        }
    }
    sort(cells.begin(), cells.end(),
    [&](const pair<int, int> &A, const pair<int, int> &B)
    {
        return a[A.first][A.second] > a[B.first][B.second];
    });

    DSU *T = new DSU(n, m);
    for (const pair<int, int> &pos : cells)
    {
        for (const pair<int, int> &delta : deltas)
        {
            pair<int, int> newPos = make_pair(pos.first + delta.first, pos.second + delta.second);
            if (isInside(newPos)
                && a[newPos.first][newPos.second] >= a[pos.first][pos.second])
            {
                T->Union(pos, newPos, a[pos.first][pos.second]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maxHeight == a[i][j])
            {
                cout << maxHeight << " ";
            }
            else
            {
                cout << answer[i][j] << " ";
            }
        }
        cout << '\n';
    }
}
