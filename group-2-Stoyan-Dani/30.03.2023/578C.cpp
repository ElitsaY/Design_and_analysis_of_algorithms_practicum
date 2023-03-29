#include <iostream>
#include <iomanip>

using namespace std;

const int MAXN = 2e5;

int n;
double a[MAXN + 5];
double aCpy[MAXN + 5];

//Kadane
double getMaxSumOfSubsegment(double x, double sign)
{
    double sum = a[0] * sign, maxSum = sum;
    for (int i = 1; i < n; i++)
    {
        if (sum > 0)
        {
            sum += a[i] * sign;
        }
        else
        {
            sum = a[i] * sign;
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

double f(double x)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] - x;
    }

    double ans = max(getMaxSumOfSubsegment(x, -1), getMaxSumOfSubsegment(x, +1));

    for (int i = 0; i < n; i++)
    {
        a[i] = aCpy[i];
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        aCpy[i] = a[i];
    }


    double l = -1e5, r = +1e5;
    for (int iter = 0; iter < 128; iter++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = f(m1);
        double f2 = f(m2);

        if (f1 < f2)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }

    cout << fixed << setprecision(10) << f(l) << '\n';
}
