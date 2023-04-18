#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 1e5;

int n;
vector<int> adj[MAXN + 5];

set<pair<int, int>> edges;

bool used[MAXN + 5];
void dfs(int x, vector<int> &cmp)
{
    used[x] = true;
    cmp.push_back(x);

    for (int y : adj[x])
    {
        if (!used[y])
        {
            dfs(y, cmp);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);

        edges.emplace(x, y);
        edges.emplace(y, x);
    }

    vector<int> answer;
    for (int x = 1; x <= n; x++)
    {
        if (!used[x])
        {
            vector<int> cmp;
            dfs(x, cmp);

            if (cmp.size() <= 2)
            {
                answer.push_back(x);
            }
            else
            {
                if (edges.count(make_pair(cmp.front(), cmp.back())))
                {
                    vector<int> opt1;
                    for (int i = 0; i < cmp.size() - 1; i += 2)
                    {
                        opt1.push_back(cmp[i]);
                    }

                    vector<int> opt2;
                    reverse(cmp.begin() + 1, cmp.end());
                    for (int i = 0; i < cmp.size() - 1; i += 2)
                    {
                        opt2.push_back(cmp[i]);
                    }

                    sort(opt1.begin(), opt1.end());
                    sort(opt2.begin(), opt2.end());
                    if (opt1 > opt2)
                    {
                        for (int y : opt2)
                        {
                            answer.push_back(y);
                        }
                    }
                    else
                    {
                        for (int y : opt1)
                        {
                            answer.push_back(y);
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < cmp.size(); i += 2)
                    {
                        answer.push_back(cmp[i]);
                    }
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    cout << answer[0];
    for (int i = 1; i < answer.size(); i++)
    {
        cout << " " << answer[i];
    }
    cout << '\n';
}
/*
6
6 1
1 3
4 2
5 2
6 5
3 4

4
1 3
4 2
3 1
4 2
*/
