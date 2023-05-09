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
int height[100001];

void makeSet(int v)
{
    parent[v] = v;
    height[v] = 0;
}

int findSet(int v)
{
    if (v == parent[v])
    {
        return v;
    }

    return parent[v] = findSet(parent[v]);
}

void unionSets(int u, int v)
{
    if (height[v] > height[u])
    {
        std::swap(u, v);
    }
    else if (height[v] == height[u])
    {
        ++height[u];
    }
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
        
        int ru = findSet(u), rv = findSet(v);
        if (ru != rv)
        {
            unionSets(ru, rv);
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