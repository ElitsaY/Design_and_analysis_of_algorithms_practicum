/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/two-sum/
 * @note The problem is changed so we print the answer instead of returning
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


using Pair = std::pair<int, int>;

int n, k;
Pair arr[100001];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }

    std::sort(arr, arr + n);

    int left = 0, right = n - 1;
    while (left <= right)
    {
        if (arr[left].first + arr[right].first == k)
        {
            printf("%d %d\n", arr[left].second, arr[right].second);

            return 0;
        }

        if (arr[left].first + arr[right].first < k)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }

    printf("Not found");

    return 0;
}