/**
 * @author Lyuben Georgiev
 * @brief Problem Sequence: https://judge.openfmi.net/practice/open_contest?contest_id=85
 * @date 23/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>
#include <deque>


int n, k;
int arr[1000000];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    std::deque<int> dq;
    int i = 0, minsIdx = 0;
    for (; i < k; ++i)
    {
        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    int best = arr[dq.front()];

    for (; i < n; ++i)
    {
        if (dq.front() == i - k)
            dq.pop_front();

        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        best = std::max(best, arr[dq.front()]);
    }

    printf("%d", best);

    return 0;
}