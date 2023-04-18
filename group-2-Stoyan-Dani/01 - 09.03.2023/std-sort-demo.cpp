#include <iostream>
#include <algorithm>

using namespace std;

struct S1
{
    int x;

    S1(){}
    S1(int x) : x(x) {}
};

bool cmp(const S1& A, const S1& B)
{
    return A.x < B.x;
}

struct S2
{
    int x;

    S2(){}
    S2(int x) : x(x) {}
};

struct CMP
{
    bool operator() (const S1& A, const S1& B)
    {
        return A.x < B.x;
    }
};

int main()
{
    int a[] = {5, 6, 1};
    sort(a, a + 3);

    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';

    int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    sort(b + 2, b + 4);

    for (int i = 0; i < 10; i++)
    {
        cout << b[i] << " ";
    }
    cout << '\n';

    vector <int> c = {6, 5, 4, 3, 2, 1};
    sort(c.begin(), c.end());

    for (int x : c)
    {
        cout << x << " ";
    }
    cout << '\n';

    vector <int> d = {6, 5, 4, 3, 2, 1};
    sort(d.begin() + 1, d.end());

    for (int x : d)
    {
        cout << x << " ";
    }
    cout << '\n';

    vector <int> e = {6, 5, 4, 3, 2, 1};
    sort(next(e.begin()), e.end());

    for (int x : e)
    {
        cout << x << " ";
    }
    cout << '\n';

    vector <S1> v1 = {S1(3), S1(2), S1(1)};
    sort(v1.begin(), v1.end(), cmp);

     //vector <S2> v2 = {S2(3), S2(2), S2(1)};
     //sort(v2.begin(), v2.end(), CMP());

    vector <S1> v3 = {S1(3), S1(2), S1(1)};
    sort(v3.begin(), v3.end(),
    [&](const S1& A, const S1& B)
    {
        return A.x < B.x;
    });
}
