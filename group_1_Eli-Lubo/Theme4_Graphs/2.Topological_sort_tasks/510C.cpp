/**
 * @author Lyuben Georgiev
 * @brief Problem: https://codeforces.com/contest/510/problem/C
 * @date 17/05/2023
 * 
*/

#include <cstdio>
#include <vector>


int n;
char names[101][101];
std::vector<char> adjList[256];
bool visited[256];
bool onPath[256];


bool topSort(char u, std::vector<char> &s)
{
    if (onPath[u])
        return true;

    onPath[u] = true;

    for (char v : adjList[u])
    {
        if (!visited[v] && topSort(v, s))
        {
            return true;
        }
    }

    visited[u] = true;
    onPath[u] = false;

    s.push_back(u);

    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", &names[i][0]);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int idx = 0;
            while (names[i][idx] != '\0' && names[i][idx] == names[j][idx])
            {
                ++idx;
            }
            if (names[i][idx] != '\0' && names[j][idx] == '\0')
            {
                printf("Impossible\n");

                return 0;
            }
            if (names[i][idx] != '\0')
            {
                adjList[names[i][idx]].push_back(names[j][idx]);
                ++idx;
            }
        }
    }

    std::vector<char> s;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (!visited[c] && topSort(c, s))
        {
            printf("Impossible\n");

            return 0;
        }
    }

    for (auto it = s.rbegin(); it != s.rend(); ++it)
    {
        printf("%c", *it);
    }

    return 0;
}