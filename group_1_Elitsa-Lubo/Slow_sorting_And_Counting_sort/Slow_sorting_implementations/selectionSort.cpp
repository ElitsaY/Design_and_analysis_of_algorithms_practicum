#include <cstdio>
#include <algorithm>


void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        int minIdx = i;
        for (int j = i+1; j < n; ++j) 
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    selectionSort(arr, n);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}