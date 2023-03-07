#include <cstdio>
#include <algorithm>
#include <cassert>
#include <numeric>


const int MAX_SIZE = 10000000;

int counts[MAX_SIZE];
int arr[MAX_SIZE];
int n;


int minInArray()
{
    int min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        min = std::min(arr[i], min);
    }

    return min;
}

int maxInArray()
{
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        max = std::max(arr[i], max);
    }
    
    return max;
}

void countingSort()
{
    // We may not need that if we know what da data is (the range of values)
    int min = minInArray(), max = maxInArray();
    // Alternative:
    // int min = std::accumulate(&arr[0], arr + n, INT_MAX, [](int a, int b){ return a < b ? a : b; });
    // int max = std::accumulate(&arr[0], arr + n, INT_MIN, [](int a, int b){ return a > b ? a : b; });

    // Check if we have the needed space (not necessary if knowing the max size and it is small enough)
    assert(max - min < MAX_SIZE);

    for (int i = 0; i < n; ++i)
    {
        ++counts[arr[i]-min];
    }

    for (int i = 0, idx = 0; i < MAX_SIZE; ++i)
    {
        for (int j = 0; j < counts[i]; ++j)
        {
            arr[idx] = i + min;
            ++idx;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    countingSort();

    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
/*
Sample input:
7
2 3 6 5 12 1 8
*/