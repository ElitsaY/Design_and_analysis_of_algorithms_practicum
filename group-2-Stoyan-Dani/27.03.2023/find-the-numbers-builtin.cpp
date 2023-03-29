#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5;

int n;
vector <int> a;

int findFirstGEQ(int x)
{
    return lower_bound(a.begin(), a.end(), x) - a.begin();
}

int findLastLEQ(int x)
{
    return (upper_bound(a.begin(), a.end(), x) - a.begin()) - 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int A, B;
        cin >> A >> B;

        int i1 = findFirstGEQ(A);
        int i2 = findLastLEQ(B);

        if (i1 == n || i2 == -1 || i1 > i2)
        {
            cout << "0" << '\n';
        }
        else
        {
            cout << i2 - i1 + 1 << '\n';
        }
    }
}
