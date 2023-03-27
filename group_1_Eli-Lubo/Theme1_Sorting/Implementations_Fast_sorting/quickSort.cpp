#include <cstdio>
#include <algorithm>


int HoarePartition(int arr[], int start, int end)
{
    int pivot = arr[start]; // Optionally generate random index to choose element at random
    int i = start - 1;
    int j = end + 1;

    while (true)
    {
        // Find leftmost element greater than or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        std::swap(arr[i], arr[j]);
    }
}

int LomutoPartition(int arr[], int start, int end)
{
    int pivot = arr[end]; // Optionally generate random index to choose element at random then swap it with end element
    int i = start - 1;  // Index of last smaller or equal element
 
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller or equal element
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]); // Put the pivot element right after last smaller element

    return (i + 1);
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end) return;

    // Using Hoare
    int pivot = HoarePartition(arr, start, end);

    quickSort(arr, start, pivot);
    quickSort(arr, pivot + 1, end);

    
    // Using Lomuto
    // int pivot = LomutoPartition(arr, start, end);

    // quickSort(arr, start, pivot - 1);
    // quickSort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}