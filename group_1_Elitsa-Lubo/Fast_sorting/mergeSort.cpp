#include <cstdio>


// We need this array for our merge algorithm to be O(n) time complexity
int merged[7];

void merge(int array[], int start, int mid, int end)
{
    int i = start, j = mid + 1, index = 0;

    while (i <= mid && j <= end)
    {
        if(array[i] <= array[j])
        {
            merged[index++] = array[i++];
        }
        else
        {
            merged[index++] = array[j++];
        }
    }

    while (i <= mid)
    {
        merged[index++] = array[i++];
    }

    while(j <= end)
    {
        merged[index++] = array[j++];
    }

    for(int k = start; k <= end; ++k)
    {
        array[k] = merged[k - start];
    }
}

void mergeSort(int array[], int start, int end)
{
    if (start >= end) return;

    int mid = start + (end - start) / 2;

    mergeSort(array, start, mid);
    mergeSort(array, mid + 1, end);

    merge(array, start, mid, end);
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}