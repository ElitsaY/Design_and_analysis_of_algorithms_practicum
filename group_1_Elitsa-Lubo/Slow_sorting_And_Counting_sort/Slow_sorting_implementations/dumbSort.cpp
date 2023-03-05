#include <cstdio>
#include <algorithm>
#include <numeric>

void dumbSort(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            if (arr[i] < arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    dumbSort(arr, n);

    // The above algorithm in one line
    // std::for_each(arr, arr + n, [&arr, n](int &i){ std::for_each(arr, arr + n, [&i](int &j){ if (i<j) std::swap(i,j); }); });

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}