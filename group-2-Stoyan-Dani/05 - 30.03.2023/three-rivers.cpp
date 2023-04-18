#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double L, G;
double W[5], S[5];

double calcDist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double solve(double pos, int ind)
{
    if (ind == 3)
    {
        return (L - pos) / G;
    }

    double l = pos, r = L;
    for (int iter = 0; iter < 64; iter++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        double f1 = calcDist(0, pos, W[ind], m1) / S[ind] + solve(m1, ind + 1);
        double f2 = calcDist(0, pos, W[ind], m2) / S[ind] + solve(m2, ind + 1);

        if (f1 < f2)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }

    return calcDist(0, pos, W[ind], l) / S[ind] + solve(l, ind + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> L >> G;
    for (int i = 0; i < 3; i++)
    {
        cin >> W[i] >> S[i];
    }

    cout << fixed << setprecision(10) << solve(0, 0) << '\n';
}

