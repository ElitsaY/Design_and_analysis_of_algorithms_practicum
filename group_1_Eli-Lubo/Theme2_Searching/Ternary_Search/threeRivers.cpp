// Problem: https://action.informatika.bg/problems/209
// Source: Stoyan-Dani

#include <cstdio>
#include <cmath>


double EPS = 1e-12;

double l, g;
double ws[3];
double ss[3];


double dist(double mx1, double my1, double mx2, double my2)
{
    return std::sqrt((mx1-mx2)*(mx1-mx2) + (my1-my2)*(my1-my2));
}

double shortestDist(int island, double curY)
{
    // Note that we can walk on the ground only on the last island because the speed is the same

    if (island == 3)
    {
        return (l - curY) / g;
    }

    double left = curY, right = l;
    while (right - left > EPS)
    {
        double m1 = left + (right - left) / 3;
        double m2 = right - (right - left) / 3;
        double f1 = shortestDist(island + 1, m1) + dist(0, curY, ws[island], m1) / ss[island];
        double f2 = shortestDist(island + 1, m2) + dist(0, curY, ws[island], m2) / ss[island];

        if (std::abs(f1 - f2) < EPS)
        {
            left = m1;
            right = m2;
        }
        else if (f1 < f2)
        {
            right = m2;
        }
        else
        {
            left = m1;
        }
    }

    return shortestDist(island + 1, left) + dist(0, curY, ws[island], left) / ss[island];
}

int main()
{
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &l, &g, &ws[0], &ss[0], &ws[1], &ss[1], &ws[2], &ss[2]);

    printf("%.11lf", shortestDist(0, 0));

    return 0;
}