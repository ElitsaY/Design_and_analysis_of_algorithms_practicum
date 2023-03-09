#include <cstdio>


// We need this array for our merge algorithm to be O(n) time complexity
int merged[7];
int inversions;

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
            // Add number of elements remaining in the left array
            inversions += (mid - i + 1);
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
    int arr[] = { 7, 1, 3, 2, 8, 5 };
    int n = 6;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\nInversions: %d\n", inversions);

    return 0;
}