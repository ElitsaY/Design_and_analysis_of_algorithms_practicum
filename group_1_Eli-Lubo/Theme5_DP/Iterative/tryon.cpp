/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/113
 * @date 25/05/2023
 * 
*/

#include <cstdio>
#include <algorithm>


int n, positive, negative;
int arr[1001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] - arr[i - 1] < 0)
        {
            negative = positive + 1;
        }
        else if (arr[i] - arr[i - 1] > 0)
        {
            positive = negative + 1;
        }
    }

    printf("%d", std::max(positive, negative) + 1);

    return 0;
}