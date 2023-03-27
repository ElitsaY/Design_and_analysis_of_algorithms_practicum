#include <cstdio>
#include <algorithm>

/**
 * Sift down value at index i.
 *
 * @param arr Array containing the heap.
 * @param n Size of the heap.
 * @param i Index of current node.
 */
void siftDown(int arr[], int n, int i)
{
    // Initialize largest as root
    int largest = i;

    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Check if root is at the wrong spot (there is a child larger than root)
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);

        siftDown(arr, n, largest); // Sift down our root
    }
}

void heapSort(int arr[], int n)
{
    // Building max heap
    for (int i = n/2; i >= 0; --i)
    {
        siftDown(arr, n, i);
    }

    // On each step swap the largest element with the last in the heap
    // Sift down the element we got after the swap
    for (int i = n - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
 
        siftDown(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    heapSort(arr, n);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}