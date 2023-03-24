/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/130
 * @date 23/03/2023
 * 
*/

#include <cstdio>


int n, k;
int arr[100420];

int cables(int length)
{
    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res += arr[i] / length;
    }

    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int left = 1, right = 1000000000;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (cables(mid) >= k)
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