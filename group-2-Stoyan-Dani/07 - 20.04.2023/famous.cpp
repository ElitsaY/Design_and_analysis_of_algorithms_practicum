#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1000;

int n, k, f, m;

string ind2Name[MAXN + 5];
map<string, int> name2Ind;

int messageCnt[MAXN + 5];
bool isFamous[MAXN + 5];

vector<int> adj[MAXN + 5];

int encode(const string& name)
{
    auto it = name2Ind.find(name);
    if (it == name2Ind.end())
    {
        int newInd = name2Ind.size();
        name2Ind[name] = newInd;
        ind2Name[newInd] = name;

        return newInd;
    }

    return it->second;
}

void bfs()
{
    queue<int> q;
    for (int x = 0; x < n; x++)
    {
        if (isFamous[x])
        {
            q.push(x);
        }
    }

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int y : adj[x])
        {
            messageCnt[y]++;
            if (messageCnt[y] >= k && !isFamous[y])
            {
                isFamous[y] = true;
                q.push(y);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> f >> m;
    for (int i = 0; i < f; i++)
    {
        string name;
        cin >> name;

        isFamous[encode(name)] = true;
    }

    set<pair<string, string>> sentMessages;
    for (int i = 0; i < m; i++)
    {
        string x, y;
        cin >> x >> y;

        if (!sentMessages.count(make_pair(x, y)))
        {
            adj[encode(x)].push_back(encode(y));
            adj[encode(y)].push_back(encode(x));
            sentMessages.emplace(x, y);
            sentMessages.emplace(y, x);
        }
    }

    bfs();

    vector<string> answer;
    for (int x = 0; x < n; x++)
    {
        if (isFamous[x])
        {
            answer.push_back(ind2Name[x]);
        }
    }
    sort(answer.begin(), answer.end());

    if (!answer.empty())
    {
        cout << answer[0];
        for (int i = 1; i < answer.size(); i++)
        {
            cout << " " << answer[i];
        }
        cout << '\n';
    }
}
