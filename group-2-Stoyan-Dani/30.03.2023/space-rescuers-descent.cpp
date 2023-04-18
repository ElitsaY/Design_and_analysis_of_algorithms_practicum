#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAXN = 100;

template <int dim>
struct Point
{
    double x[dim];
};

template <int dim>
double dist(const Point<dim> &A, const Point<dim> &B)
{
    double r = 0;
    for (int i = 0; i < dim; i++)
    {
        r += (A.x[i] - B.x[i]) * (A.x[i] - B.x[i]);
    }

    return sqrt(r);
}

int n;
Point<3> a[MAXN + 5];

double eval(const Point<3> &P)
{
    double maxDist = -1;
    for (int i = 0; i < n; i++)
    {
        maxDist = max(maxDist, dist(P, a[i]));
    }

    return maxDist;
}

double optimize(int dim, Point<3> P)
{
    double l = -1e4, r = 1e4;
    for (int iter = 0; iter < 64; iter++)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        P.x[dim] = m1;
        double f1 = eval(P);

        P.x[dim] = m2;
        double f2 = eval(P);

        //cout << dim << " " << m1 << " " << m2 << " || " << f1 << " " << f2 << '\n';

        if (f1 < f2)
        {
            r = m2;
        }
        else
        {
            l = m1;
        }
    }

    return l;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].x[0] >> a[i].x[1] >> a[i].x[2];
    }

    Point<3> P;
    P.x[0] = P.x[1] = P.x[2] = 0;
    //P.x[0] = 4.0;
    //P.x[1] = -2.5;
    //P.x[2] = 0.5;
    for (int iter = 0; iter < 2; iter++)
    {
        for (int dim = 0; dim < 3; dim++)
        {
            P.x[dim] = optimize(dim, P);
        }
    }

    Point<3> P1;
    P1.x[0] = 3.0000000166;
    P1.x[1] = -1.8214285475;
    P1.x[2] = -0.0000001127;

    Point<3> P2;
    P2.x[0] = 4.0000068501;
    P2.x[1] = -2.5000015036;
    P2.x[2] = 0.5000626514;

    cout << eval(P1) << " " << eval(P2) << '\n';
}
