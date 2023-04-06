/**
 * @author Lyuben Georgiev
 * @brief Problem Спасители на плажа: https://judge.openfmi.net/practice/open_contest?contest_id=153
 * @date 06/04/2023
 * 
*/

#include <cstdio>
#include <cmath>
#include <algorithm>

double EPS = 1e-9;

int t;
int mx1, my1, mx2, my2, v1, v2;


double f(double mid)
{
    double fmy1 = my1, fmy2 = my2;
    return std::sqrt(((double)mx1-mid)*((double)mx1-mid) + fmy1*fmy1) / v1 + std::sqrt(((double)mx2-mid)*((double)mx2-mid) + fmy2*fmy2) / v2;
}

double ternarySearch(double l, double r)
{
    while (r - l > EPS) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);
        double f2 = f(m2);


        if (std::abs(f1 - f2) < EPS)
        {
            l = m1;
            r = m2;
        }
        else if (f1 < f2)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }

    return f(l);
}

int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d %d %d %d %d %d", &mx1, &my1, &mx2, &my2, &v1, &v2);
    }

    printf("%.5f", ternarySearch(std::min(mx1, mx2), std::max(mx1, mx2)));

    return 0;
}