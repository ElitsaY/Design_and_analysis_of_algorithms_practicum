#include <cstdio>


void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        int element = arr[i];

        int j;
        for (j = i-1; j >= 0 && arr[j] > element; --j)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = element;
    }
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    insertionSort(arr, n);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}