/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/65
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


const int MIN = -100000000;

int arr[10420];
short int counts[200000001];

int main()
{
    int n, left, right;
    long long int res = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        ++counts[arr[i] - MIN];
    }

    std::sort(arr, arr + n);

    for (int i = 0; i < n - 2; ++i)
    {
        --counts[arr[i] - MIN];
        int chosen = arr[i];
        
        long long int twiceCount = 0;

        for (int j = i + 1; j < n; j++)
        {
            int target = -chosen - arr[j] - MIN;
            if (target < 0 || target > 200000000) continue;

            twiceCount += (long long)counts[target];

            if (target + MIN == arr[j])
            {
                --twiceCount;
            }
        }

        res += twiceCount / 2;
    }

    printf("%lld", res);
 
    return 0;
}