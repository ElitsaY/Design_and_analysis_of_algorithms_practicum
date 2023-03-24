/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/168
 * @date 23/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, m;
long long int arr[100420];

bool possible(long long int k)
{
    long long int maxSum = arr[0] + k, curSum = maxSum;
 
    for (long long int i = 2; i <= (long long)n; ++i)
    {
        curSum = std::max(arr[i-1] + i*k, curSum + arr[i-1] + i*k);
        maxSum = std::max(maxSum, curSum);
    }

    return maxSum >= m;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &arr[i]);
    }

    int left = -1002000000, right = 1002000000;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (possible(mid))
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d", right + 1);

    return 0;
}