/**
 * @author Lyuben Georgiev
 * @brief Problem 112C: https://judge.openfmi.net/practice/open_contest?contest_id=178
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <vector>


int n, m, q, a, b, curComp;
std::vector<int> adj[1001];
int components[1001];


void dfs(int node)
{
    components[node] = curComp;
    for (int to : adj[node])
    {
        if (!components[to])
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

    for (int i = 1; i <= n; ++i)
    {
        if (!components[i])
        {
            curComp = i;
            dfs(i);
        }
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d", components[a] == components[b]);
    }

    return 0;
}