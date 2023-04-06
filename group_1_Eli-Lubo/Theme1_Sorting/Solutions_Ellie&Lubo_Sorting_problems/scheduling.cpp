/**
 * @author Lyuben Georgiev
 * @brief Problem Scheduling: https://judge.openfmi.net/practice/open_contest?contest_id=21
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <algorithm>

int s, e;
std::pair<int, int> arr[1000000];

int main()
{
    int i = 0;
    // Note that arr[i].second is the start time and arr[i].first is the end time
    while (scanf("%d %d", &arr[i].second, &arr[i].first) != EOF)
    {
        arr[i].first += arr[i].second;
        ++i;
    }
    std::sort(arr, arr + i);

    int res = 0, last = -1;
    for (int j = 0; j < i; ++j)
    {
        if (arr[j].second >= last)
        {
            ++res;
            last = arr[j].first;
        }
    }

    printf("%d\n", res);

    return 0;
}