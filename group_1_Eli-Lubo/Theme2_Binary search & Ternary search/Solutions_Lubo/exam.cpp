/**
 * @author Lyuben Georgiev
 * @brief Problem: https://action.informatika.bg/problems/117
 * @date 23/03/2023
 * 
*/

#include <cstdio>


long long int n, f, fSum;

long long int sumFirstK(long long int k)
{
    return (((f+k)*(f+k-1)) / 2LL) - fSum;
}

int main()
{
    scanf("%lld %lld", &n, &f);
    fSum = (f*(f-1)) / 2LL;
    
    // I chose right to be 3037000500 because
    // it is around the sqrt of max value for N (10^18)
    // I use sqrt because the sum formula is X * (X+1) / 2
    // and I know that (X*X) >= (X * (X+1) / 2)
    // So sqrt of max possible N is a good upper bound
    long long int left = 0, right = 3037000500;
    while (left <= right)
    {
        long long int mid = left + (right - left) / 2;
        if (sumFirstK(mid) >= n)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%lld", right + 1);

    return 0;
}