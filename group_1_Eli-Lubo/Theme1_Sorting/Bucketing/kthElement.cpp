/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/162
 * @date 16/03/2023
 * 
*/

#include <cstdio>


const int BUCKET_SIZE = 50000;

int n, k;
long long int FIRST, MUL, ADD, MOD;

int buckets[50000];
int targetBucket[50100];

int main()
{
    scanf("%d%d %lld%lld%lld%lld", &k, &n, &FIRST, &MUL, &ADD, &MOD);

    // Fill the buckets
    int curElem = FIRST;
    ++buckets[FIRST / BUCKET_SIZE];
    for (int i = 1; i < n; ++i)
    {
        curElem = ((long long)curElem * MUL + ADD) % MOD;
        ++buckets[curElem / BUCKET_SIZE];
    }

    // Find in which bucket is our element and his position in the bucket
    int elemsCnt = buckets[0], bucketIdx = 0, kthInBucket = k;
    while (elemsCnt < k)
    {
        kthInBucket = k - elemsCnt;
        ++bucketIdx;
        elemsCnt += buckets[bucketIdx];
    }

    // Do counting of the elements in the target bucket
    curElem = FIRST;
    if (FIRST / BUCKET_SIZE == bucketIdx)
        ++targetBucket[FIRST % BUCKET_SIZE];
    for (int i = 1; i < n; ++i)
    {
        curElem = ((long long)curElem * MUL + ADD) % MOD;
        if (curElem / BUCKET_SIZE == bucketIdx)
        {
            ++targetBucket[curElem % BUCKET_SIZE];
        }
    }

    // Iterate counts till finding kthInBucket
    int i = 0;
    while (kthInBucket > 0)
    {
        kthInBucket -= targetBucket[i];
        if (kthInBucket > 0)
            ++i;
    }

    // Formula for result is (Index + BEGIN_OF_BUCKET)
    printf("%d", i + bucketIdx * BUCKET_SIZE);

    return 0;
}