#include <iostream>
#include <cmath>

#define double long double

using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    //a^x = b

    double l = 0, r = 10, mid;
    for (int iter = 0; iter < 128; iter++)
    {
        mid = (l + r) / 2;

        if (pow(a, mid) <= b)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << a << "^" << mid << " = " << b << '\n';
}
