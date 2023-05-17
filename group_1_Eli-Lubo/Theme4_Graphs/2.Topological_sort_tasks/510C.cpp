/**
 * @author Lyuben Georgiev
 * @brief Problem: https://codeforces.com/contest/510/problem/C
 * @date 17/05/2023
 * 
*/

#include <cstdio>
#include <vector>

int n;
char ws[101][101];
std::vector<char> adjList[256];
bool visited[256];
bool onPath[256];
std::vector<char> s;

bool topSort(char u)
{
    if (onPath[u])
        return true;

    onPath[u] = true;

    for (char v : adjList[u])
    {
        if (!visited[v] && topSort(v))
        {
            return true;
        }
    }

    onPath[u] = false;
    visited[u] = true;

    s.push_back(u);

    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", &ws[i][0]);
    }

    for (int i = 1; i < n; ++i)
    {
        int idx = 0;
        while (ws[i-1][idx] != '\0' && ws[i-1][idx] == ws[i][idx])
        {
            ++idx;
        }

        if (ws[i-1][idx] != '\0' && ws[i][idx] == '\0')// f t
        {
            printf("Impossible\n");

            return 0;
        }

        if (ws[i-1][idx] != '\0')// f f
        {
            adjList[ws[i-1][idx]].push_back(ws[i][idx]);
        }
    }

    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (!visited[c] && topSort(c))
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