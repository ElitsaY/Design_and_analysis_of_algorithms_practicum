/**
 * @author Lyuben Georgiev
 * @brief Problem Sequence: https://judge.openfmi.net/practice/open_contest?contest_id=85
 * @date 23/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, k;
int arr[1000000];

bool existsSubarray(int minimum)
{
    int curLen = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < minimum)
        {
            curLen = 0;
        }
        else
        {
            ++curLen;
            if (curLen == k)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int left = 1, right = 2000000;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (existsSubarray(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    printf("%d", left - 1);

    return 0;
}