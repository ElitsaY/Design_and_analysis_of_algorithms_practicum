#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int MAXN = 1e5;

struct AdjacentElement
{
    int x;
    int w;

    AdjacentElement(){}
    AdjacentElement(int x, int w) : x(x), w(w) {}
};

int n;
int p[MAXN + 5];
vector<AdjacentElement> adj[MAXN + 5];

int cmp[MAXN + 5];
void dfs(int x, int currComp, int minWeight)
{
    cmp[x] = currComp;

    for (AdjacentElement &e : adj[x])
    {
        if (cmp[e.x] == -1 && e.w >= minWeight)
        {
            dfs(e.x, currComp, minWeight);
        }
    }
}

bool check(int minWeight)
{
    for (int x = 1; x <= n; x++)
    {
        cmp[x] = -1;
    }

    for (int x = 1; x <= n; x++)
    {
        if (cmp[x] == -1)
        {
            dfs(x, x, minWeight);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cmp[i] != cmp[p[i]])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ifstream cin("wormsort.in");
    ofstream cout("wormsort.out");

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    vector<int> weights;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].emplace_back(y, w);
        adj[y].emplace_back(x, w);

        weights.push_back(w);
    }

    sort(weights.begin(), weights.end());

    if (check(1e9 + 5))
    {
        cout << "-1" << '\n';
        return 0;
    }

    int l = 0, r = weights.size() - 1, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (check(weights[mid]))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (check(weights[r]))
    {
        cout << weights[r] << '\n';
    }
    else
    {
        cout << weights[l] << '\n';
    }
}
