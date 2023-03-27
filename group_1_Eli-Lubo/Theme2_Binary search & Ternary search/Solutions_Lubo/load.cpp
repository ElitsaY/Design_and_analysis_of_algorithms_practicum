/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/141
 * @date 23/03/2023
 * 
*/

#include <cstdio>


int n, k;
int arr[100420];

bool possible(int fuelCapacity)
{
    int currentFuel = fuelCapacity - arr[0], loads = k;
    for (int i = 1; i < n; ++i)
    {
        int distance = arr[i] - arr[i-1];

        if (currentFuel < distance)
        {
            currentFuel = fuelCapacity;
            --loads;
        }

        currentFuel -= distance;

        if (distance > fuelCapacity || loads < 0)
        {
            return false;
        }
    }

    return true;
}


int main()
{
    scanf("%d %d", &n, &k);
    scanf("%d", &arr[n]);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    ++n;

    int left = 1, right = 1000000000;
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