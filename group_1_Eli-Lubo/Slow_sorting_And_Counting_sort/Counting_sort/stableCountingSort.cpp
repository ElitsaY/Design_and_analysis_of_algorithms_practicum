#include <cstdio>
#include <algorithm>
#include <cassert>
#include <numeric>


using Pair = std::pair<int, int>;

const int MAX_SIZE = 10000000;

int counts[MAX_SIZE];
Pair result[MAX_SIZE];
Pair arr[MAX_SIZE];
int n;


int minInArray()
{
    int min = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        min = std::min(arr[i].first, min);
    }

    return min;
}

int maxInArray()
{
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        max = std::max(arr[i].first, max);
    }
    
    return max;
}

void countingSort()
{
    int min = minInArray(), max = maxInArray();
    // Alternative:
    // int min = std::accumulate(&arr[0], arr + n, INT_MAX, [](int a, Pair b){ return a < b.first ? a : b.first; });
    // int max = std::accumulate(&arr[0], arr + n, INT_MIN, [](int a, Pair b){ return a > b.first ? a : b.first; });

    // Check if we have the needed space (not necessary if knowing the max size and it is small enough)
    assert(max - min < MAX_SIZE);

    for (int i = 0; i < n; ++i)
    {
        ++counts[arr[i].first - min];
    }

    // Build the prefix sums
    for (int i = 1; i < MAX_SIZE; ++i)
    {
        counts[i] += counts[i-1];
    }

    for (int i = n-1; i >= 0; --i)
    {
        result[counts[arr[i].first - min] - 1] = arr[i];
        --counts[arr[i].first - min];
    }

    for (int i = 0; i < n; ++i)
    {
        arr[i] = result[i];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }

    // Stable sort elements by first number
    countingSort();

    for (int i = 0; i < n; ++i)
    {
        printf("{%d, %d} ", arr[i].first, arr[i].second);
    }

    return 0;
}

/*
Sample input:
12
2 1
2 2
2 3
5 4 
5 5 
1 6 
19 7 
2 8 
19 9 
5 10 
6 11
1 12
*/