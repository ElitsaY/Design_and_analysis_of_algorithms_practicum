/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/68
 * @date 23/03/2023
 * 
*/

#include <cstdio>
#include <algorithm>

#define MAX_NUM 1000000007
#define MIN_NUM -1000000007

int n, potLen, interval, first, next, mul, add;

struct Bucket
{
    int start;
    int end;

    Bucket()
        : start(MAX_NUM), end(MIN_NUM) {}

    void expand(int newBorder)
    {
        start = std::min(start, newBorder);
        end = std::max(end, newBorder);
    }
};

Bucket buckets[11000000];

int main()
{
    scanf("%d %d %d %d %d %d", &n, &potLen, &interval, &first, &mul, &add);

    int bucketsCnt = (potLen + 1) / interval + ((potLen + 1) % interval > 0);

    if (bucketsCnt - 2 > n)
    {
        printf("-1");

        return 0;
    }

    buckets[0].end = 0;
    buckets[bucketsCnt - 1].start = potLen;

    int remaining = bucketsCnt - 1, i = 0;
    for (; i < n && remaining > 0; ++i)
    {
        int bucketIdx = first / interval;
        int oldStart = buckets[bucketIdx].start;
        int oldEnd = buckets[bucketIdx].end;
        buckets[bucketIdx].expand(first);

        int changeCur = oldStart == MAX_NUM || oldEnd == MIN_NUM, changePrev = 0, changeNext = 0;
        if (bucketIdx)
        {
            changePrev = oldStart - buckets[bucketIdx-1].end > interval && buckets[bucketIdx].start - buckets[bucketIdx-1].end <= interval;
        }
        if (bucketIdx + 1 < bucketsCnt)
        {
            changeNext = buckets[bucketIdx+1].start - oldEnd > interval && buckets[bucketIdx+1].start - buckets[bucketIdx].end <= interval;
        }
        remaining -= (changePrev + changeNext);

        first = ((long long)first * (long long)mul + (long long)add) % (long long)(potLen + 1);
    }

    printf("%d", remaining ? -1 : i);

    return 0;
}