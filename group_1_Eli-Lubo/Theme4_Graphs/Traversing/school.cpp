/**
 * @author Lyuben Georgiev
 * @brief Problem Школа: https://judge.openfmi.net/practice/open_contest?contest_id=178
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <vector>


int n, m, q, a, b;
std::vector<int> adj[501];
bool visited[501];


void dfs(int node)
{
    visited[node] = true;
    for (int to : adj[node])
    {
        if (!visited[to])
        {
            dfs(to);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            ++res;
            dfs(i);
        }
    }

    printf("%d", res);

    return 0;
}