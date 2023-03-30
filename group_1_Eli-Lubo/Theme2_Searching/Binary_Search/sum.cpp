/**
 * @author Lyuben Georgiev
 * @brief Problem : https://judge.openfmi.net/practice/open_contest?contest_id=37
 * @date 30/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, m, si;
int arr[1000001];


bool exists()
{
    int l = 0, r = n-1;
    while (l < r)
    {
        if (arr[l] + arr[r] == si)
        {
            return true;
        }
        if (arr[l] + arr[r] < si)
        {
            ++l;
        }
        else
        {
            --r;
        }
    }

    return false;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &si);

        printf(exists() ? "YES\n" : "NO\n");
    }

    return 0;
}