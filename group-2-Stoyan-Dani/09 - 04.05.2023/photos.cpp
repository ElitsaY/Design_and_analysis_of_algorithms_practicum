#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 2000;

struct DSU
{
    int sz[MAXN+5][MAXN+5];
    pair <int, int> parent[MAXN+5][MAXN+5];

    DSU(){}
    DSU(int n, int m)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                sz[i][j] = 1;
                parent[i][j] = {i, j};
            }
        }
    }

    pair <int, int> Find(pair <int, int> x)
    {
        if(parent[x.first][x.second]==x) return x;

        parent[x.first][x.second] = Find(parent[x.first][x.second]);
        return parent[x.first][x.second];
    }

    bool Union(pair <int, int> x, pair <int, int> y)
    {
        x = Find(x);
        y = Find(y);

        if(x==y) return false;
        if(sz[x.first][x.second]<sz[y.first][y.second]) swap(x, y);

        parent[y.first][y.second] = x;
        sz[x.first][x.second] += sz[y.first][y.second];

        return true;
    }

    bool areConnected(pair <int, int> x, pair <int, int> y)
    {
        return (Find(x)==Find(y));
    }
};

int n, m;
char grid[MAXN+5][MAXN+5];

int reporterDist[MAXN+5][MAXN+5];
void bfs()
{
    queue <pair <int, int>> q;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            reporterDist[i][j] = MAXN*MAXN;
            if(grid[i][j]=='+')
            {
                reporterDist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    while(q.empty()==false)
    {
        pair <int, int> x = q.front();
        q.pop();

        int currD = reporterDist[x.first][x.second];

        if(x.first-1>=0 && reporterDist[x.first-1][x.second]>currD+1)
        {
            q.emplace(x.first-1, x.second);
            reporterDist[x.first-1][x.second] = currD + 1;
        }
        if(x.first+1<n && reporterDist[x.first+1][x.second]>currD+1)
        {
            q.emplace(x.first+1, x.second);
            reporterDist[x.first+1][x.second] = currD + 1;
        }
        if(x.second-1>=0 && reporterDist[x.first][x.second-1]>currD+1)
        {
            q.emplace(x.first, x.second-1);
            reporterDist[x.first][x.second-1] = currD + 1;
        }
        if(x.second+1<m && reporterDist[x.first][x.second+1]>currD+1)
        {
            q.emplace(x.first, x.second+1);
            reporterDist[x.first][x.second+1] = currD + 1;
        }
    }
}

pair <int, int> P, C;
vector <pair<int, int>> allCells;

int pref[MAXN*2+5];
int cellInd[MAXN+5][MAXN+5];

void init()
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(grid[i][j]=='P') P = {i, j};
            else if(grid[i][j]=='C') C = {i, j};
        }
    }

    bfs();

    //Count sort
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            pref[reporterDist[i][j]+1]++;
    for(int i = 2;i<=2*MAXN+1;i++) pref[i] += pref[i-1];

    allCells.resize(n*m);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cellInd[i][j] = pref[reporterDist[i][j]];
            pref[reporterDist[i][j]]++;

            allCells[cellInd[i][j]] = {i, j};
        }
    }
    reverse(allCells.begin(), allCells.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0;i<n;i++) cin >> grid[i];

    init();

    DSU dsu(n, m);
    for(pair <int, int> cell: allCells)
    {
        int currD = reporterDist[cell.first][cell.second];

        if(cell.first-1>=0 && reporterDist[cell.first-1][cell.second]>=currD)
            dsu.Union(cell, {cell.first-1, cell.second});
        if(cell.first+1<n && reporterDist[cell.first+1][cell.second]>=currD)
            dsu.Union(cell, {cell.first+1, cell.second});
        if(cell.second-1>=0 && reporterDist[cell.first][cell.second-1]>=currD)
            dsu.Union(cell, {cell.first, cell.second-1});
        if(cell.second+1<m && reporterDist[cell.first][cell.second+1]>=currD)
            dsu.Union(cell, {cell.first, cell.second+1});

        if(dsu.areConnected(P, C)==true)
        {
            cout << reporterDist[cell.first][cell.second] << '\n';
            return 0;
        }
    }
}
