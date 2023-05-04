/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/158
 * @date 04/05/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, m;
int parent[100001];
int size[100001];

int root(int u)
{
    while (u != parent[u])
    {
        u = parent[u];
    }

    return u;
}

void join(int u, int v)
{
    if (size[v] > size[u])
        std::swap(u, v);
    else if (size[v] == size[u])
        ++size[u];
    parent[v] = parent[u];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    if (n == 1)
    {
        printf("0");

        return 0;
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        
        int ru = root(u), rv = root(v);
        if (ru != rv)
        {
            join(ru, rv);
            --n;
            if (n == 1)
            {
                printf("%d", i + 1);

                return 0;
            }
        }
    }

    printf("-1");

    return 0;
}