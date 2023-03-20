/**
 * @author Lyuben Georgiev
 * @brief Problem Evil: https://judge.openfmi.net/practice/open_contest?contest_id=175
 * @date 09/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>

// Note that by using bit fields we cut the memory by half
struct Point
{
    unsigned int val : 31; // 31 bits
    unsigned int isStart : 1; // 1 bit

    bool operator <(const Point &other)
    {
        return val < other.val || (val == other.val && isStart);
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
        arr[i] = {(unsigned int)from, 1};
        arr[m+i] = {(unsigned int)to, 0};
    }
    std::sort(arr, arr + 2*m);

    int starts = 0, ends = 0, res = 0, start;
    for (int i = 0; i < 2*m; ++i)
    {
        if (arr[i].isStart)
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