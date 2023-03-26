#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#define double long double

using namespace std;

const double PI = acos(-1);
const double eps = 0.000000001;

double degToRad(double x)
{
    return (x/180)*PI;
}

double radToDeg(double x)
{
    return (x/PI)*180;
}

struct Vector2
{
    double x, y;

    Vector2(){}
    Vector2(double x, double y) : x(x), y(y) {}

    double mag2()
    {
        return x*x + y*y;
    }

    double mag()
    {
        return sqrt(x*x + y*y);
    }

    Vector2 normalized();
    Vector2 rotated(double ang)
    {
        return Vector2(x*cos(ang) - y*sin(ang), x*sin(ang) + y*cos(ang));
    }
};

Vector2 operator +(const Vector2& A, const Vector2& B)
{
    return Vector2(A.x+B.x, A.y+B.y);
}

Vector2 operator -(const Vector2& A)
{
    return Vector2(-A.x, -A.y);
}

Vector2 operator -(const Vector2& A, const Vector2& B)
{
    return Vector2(A.x-B.x, A.y-B.y);
}

Vector2 operator *(const Vector2& A, const double a)
{
    return Vector2(A.x*a, A.y*a);
}

Vector2 operator /(const Vector2& A, const double a)
{
    return Vector2(A.x/a, A.y/a);
}

Vector2 operator *(const double a, const Vector2& A)
{
    return Vector2(A.x*a, A.y*a);
}

Vector2 Vector2::normalized()
{
    return (*this)/mag();
}

double calcArea(const Vector2& A, const Vector2& B, const Vector2& C)
{
    return ((A.x*B.y + A.y*C.x + B.x*C.y) - (A.y*B.x + A.x*C.y + B.y*C.x))*0.5;
}

bool operator <(Vector2 A, Vector2 B)
{
    if(abs(A.x-B.x)>eps) return A.x+eps<B.x;
    return A.y+eps<B.y;
}

bool operator >(Vector2 A, Vector2 B)
{
    if(abs(A.x-B.x)>eps) return A.x+eps>B.x;
    return A.y+eps>B.y;
}

struct Line
{
    //Ax + By + C = 0;
    double A, B, C;

    Line(){}
    Line(Vector2 P1, Vector2 P2)
    {
        this->A = P1.y - P2.y;
        this->B = P2.x - P1.x;
        this->C = P1.y*(P1.x-P2.x) - P1.x*(P1.y-P2.y);
    }

    double getY(double x) const
    {
        return (-C-A*x)/B;
    }

    pair <Vector2, Vector2> sample2() const
    {
        if(abs(B)>eps) return {Vector2(1, getY(1)), Vector2(2, getY(2))};
        else
        {
            double x = -C/A;
            return {Vector2(x, 1), Vector2(x, 2)};
        }
    }

    bool isIn(const Vector2& P) const
    {
        return abs(A * P.x + B * P.y + C) < eps;
    }
};

vector <Vector2> intersect(const Line& l1, const Line& l2)
{
    if(abs(l1.A)>eps) //l1.A != 0
    {
        double y = (l2.A*l1.C - l2.C*l1.A)/(l1.A*l2.B - l1.B*l2.A);
        double x = (-l1.C-l1.B*y)/l1.A;

        return {Vector2(x, y)};
    }
    else
    {
        double x = (l2.B*l1.C - l1.B*l2.C)/(l1.B*l2.A - l2.B*l1.A);
        double y = (-l1.C-l1.A*x)/l1.B;

        return vector<Vector2>{Vector2(x, y)};
    }
}

Vector2 project(const Line &l, const Vector2& P)
{
    pair <Vector2, Vector2> a = l.sample2();

    Vector2 v = a.first - a.second;
    v = v.rotated(PI/2);

    Vector2 P1 = P + v;
    Line l1(P, P1);

    return intersect(l, l1)[0];
}

struct Segment
{
    Vector2 P1, P2;

    Segment(){}
    Segment(const Vector2 &P1, const Vector2 &P2) : P1(P1), P2(P2) {}

    Line getLine() const
    {
        return Line(P1, P2);
    }

    bool isIn(const Vector2& P) const
    {
        if(min(P1.x, P2.x) - eps <= P.x && P.x <= max(P1.x, P2.x) + eps
            && min(P1.y, P2.y) - eps <= P.y && P.y <= max(P1.y, P2.y) + eps)
        {
            return getLine().isIn(P);
        }

        return false;
    }
};

struct Circle
{
    Vector2 O;
    double r;

    Circle(){}
    Circle(const Vector2& O, double r) : O(O), r(r) {}

    bool isIn(const Vector2& P) const
    {
        return (P - O).mag2() <= r * r;
    }
};

vector <Vector2> intersect(const Circle &c, const Line &l)
{
    if (abs(l.A) > eps)
    {
        double V1 = l.B * l.B + l.A * l.A;
        double V2 = 2 * l.B * l.C + 2 * l.A * l.B * c.O.x - 2 * l.A * l.A * c.O.y;
        double V3 = l.C * l.C + l.A * l.A * c.O.x * c.O.x + 2 * l.A * l.C * c.O.x + l.A * l.A * c.O.y * c.O.y - l.A * l.A * c.r * c.r;

        double D = V2 * V2 - 4 * V1 * V3;
        //cout << V1 << " " << V2 << " " << V3 << " -> " << D << '\n';
        if (D < 0)
        {
            return {};
        }

        double y1 = (-V2 - sqrt(D)) / (2 * V1);
        double x1 = (-l.B * y1 - l.C) / l.A;

        double y2 = (-V2 + sqrt(D)) / (2 * V1);
        double x2 = (-l.B * y2 - l.C) / l.A;

        return vector<Vector2>{Vector2(x1, y1), Vector2(x2, y2)};
    }
    else
    {
        double V1 = l.A * l.A + l.B * l.B;
        double V2 = 2 * l.A * l.C + 2 * l.B * l.A * c.O.y - 2 * l.B * l.B * c.O.x;
        double V3 = l.C * l.C + l.B * l.B * c.O.y * c.O.y + 2 * l.B * l.C * c.O.y + l.B * l.B * c.O.x * c.O.x - l.B * l.B * c.r * c.r;

        double D = V2 * V2 - 4 * V1 * V3;
        if (D < 0)
        {
            return {};
        }

        double x1 = (-V2 - sqrt(D)) / (2 * V1);
        double y1 = (-l.A * x1 - l.C) / l.B;

        double x2 = (-V2 + sqrt(D)) / (2 * V1);
        double y2 = (-l.A * x2 - l.C) / l.B;

        return vector<Vector2>{Vector2(x1, y1), Vector2(x2, y2)};
    }
}

vector <Vector2> intersect(const Circle &c, const Segment &s)
{
    vector <Vector2> lineIntersections = intersect(c, s.getLine());

    vector <Vector2> res;
    for (const Vector2 &P : lineIntersections)
    {
        if (s.isIn(P))
        {
            res.push_back(P);
        }
    }

    return res;
}
// -----------------------------------------------------------------

double findMinDistance(const Vector2 &P, const vector<Vector2> &polygon)
{
    double l = 0, r = 1e8, mid;
    for (int iter = 0; iter < 64; iter++)
    {
        mid = (l + r) / 2;
        bool foundPointIn = false;

        Circle c(P, mid);
        for (int i = 0; i < polygon.size(); i++)
        {
            if (c.isIn(polygon[i]))
            {
                foundPointIn = true;
                break;
            }

            if (intersect(c, Segment(polygon[i], polygon[(i + 1) % polygon.size()])).size() > 0)
            {
                foundPointIn = true;
                break;
            }
        }

        if (foundPointIn)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    return l;
}

double findMaxDistance(const Vector2 &P, const vector<Vector2> &polygon)
{
    double maxDist2 = -1;
    for (const Vector2 &A : polygon)
    {
        maxDist2 = max(maxDist2, (P - A).mag2());
    }

    return sqrt(maxDist2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Vector2 P;
    cin >> P.x >> P.y;

    vector<Vector2> polygon(n);
    for (int i = 0; i < n; i++)
    {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double minDist = findMinDistance(P, polygon);
    double maxDist = findMaxDistance(P, polygon);

    cout << fixed << setprecision(15) << PI*maxDist*maxDist - PI*minDist*minDist << '\n';
}
