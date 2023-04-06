/**
 * @author Lyuben Georgiev
 * @brief Problem Socks: https://action.informatika.bg/problems/226
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, p;
int arr[100001];

bool possible(int diff)
{
    int pairs = 0;
    for (int i = 1; i < n && pairs < p; ++i)
    {
        if (arr[i] - arr[i-1] <= diff)
        {
            ++pairs;
            ++i;
        }
    }

    return pairs == p;
}

int main()
{
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    std::sort(arr, arr + n);

    int l = 0, r = 1000000000;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (possible(m))
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    printf("%d", l);

    return 0;
}