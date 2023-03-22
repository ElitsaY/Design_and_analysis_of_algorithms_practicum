#include <iostream>

using namespace std;

const int MAXN = 2e5;

int n;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i< n; i++)
    {
        cin >> a[i];
    }

    int ptr = n;
    int64_t maxSum = 0, sum1 = 0, sum3 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];

        while (ptr - 1 >= 0 && sum3 + a[ptr - 1] <= sum1)
        {
            ptr--;
            sum3 += a[ptr];
        }

        if (ptr <= i)
        {
            break;
        }
        if (sum1 == sum3)
        {
            maxSum = max(maxSum, sum1);
        }
    }

    cout << maxSum << '\n';
}
