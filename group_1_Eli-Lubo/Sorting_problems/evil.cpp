/**
 * @author Lyuben Georgiev
 * @brief Problem Evil: https://judge.openfmi.net/practice/open_contest?contest_id=175
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>


struct Point
{
    int val;
    bool start;

    bool operator <(const Point &other)
    {
        return val < other.val || (val == other.val && start);
    }
};

int n, m;
Point arr[2000420];

int main()
{
    int from, to;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &from, &to);
        arr[i] = {from, true};
        arr[m+i] = {to, false};
    }
    std::sort(arr, arr + 2*m);

    int starts = 0, ends = 0, res = 0, start;
    for (int i = 0; i < 2*m; ++i)
    {
        if (arr[i].start)
        {
            if (starts == ends)
            {
                start = arr[i].val;
            }
            ++starts;
        }
        else
        {
            ++ends;
        }

        if (starts == ends)
        {
            res += (arr[i].val - start + 1);
        }
    }

    printf("%d", res);

    return 0;
}