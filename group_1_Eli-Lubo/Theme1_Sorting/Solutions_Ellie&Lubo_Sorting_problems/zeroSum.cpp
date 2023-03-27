/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/65
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n;
long long int res;
int arr[10420];


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    std::sort(arr, arr + n);

    for (int i = 0; i < n; ++i)
    {
        int target = -arr[i];

        int left = i + 1, right = n-1;
        while (left < right)
        {
            if (arr[left] + arr[right] < target)
                ++left;
            else if (arr[left] + arr[right] > target)
                --right;
            else
            {
                if (arr[left] == arr[right]) // All elements in [left..right] are the same
                {
                    // Number of elements in the range [left..right]
                    int count = right - left + 1;
                    // Number of pairs is Combination of 2 chosen from count
                    // Formula: N(N-1)/2
                    res += ((long long)count * ((long long)count - 1LL)) / 2LL;
                    break;
                }

                int leftCnt = 1, rightCount = 1;
                while (left < right && arr[left] == arr[left+1])
                {
                    ++leftCnt;
                    ++left;
                }
                while (left < right && arr[right] == arr[right-1])
                {
                    ++rightCount;
                    --right;
                }

                res += (long long)(leftCnt * rightCount);
                ++left;
                --right;
            }
        }
    }

    printf("%lld", res);

    return 0;
}