#include <cstdio>
#include <algorithm>


void bubbleSort(int arr[], int n)
{
    bool changed = true; // Used for short circuiting
    for(int i = 0; i < n && changed; ++i)
    {
        changed = false;
        int last = n - i; // Last i elements are at the right place
        for (int j = 1; j < last; ++j) 
        {
            if (arr[j-1] > arr[j])
            {
                changed = true;
                std::swap(arr[j-1], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = { 2, 3, 6, 5, 12, 1, 8 };
    int n = 7;

    bubbleSort(arr, n);

    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}