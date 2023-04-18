#include <iostream>

using namespace std;

const int MAXN = 1e5;

int n;
int a[MAXN + 5];

int findFirstGEQ(int x)
{
    int l = 0, r = n - 1, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;

        if (a[mid] >= x)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    if (a[l] >= x)
    {
        return l;
    }
    if (a[r] >= x)
    {
        return r;
    }
    return n;
}

int findLastLEQ(int x)
{
    int l = 0, r = n - 1, mid;
    while(l + 1 < r)
    {
        mid = (l + r) / 2;

        if (a[mid] <= x)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (a[r] <= x)
    {
        return r;
    }
    if (a[l] <= x)
    {
        return l;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
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
