#include <iostream>
#include <random>

using namespace std;

const int MAXN = 1e5;

mt19937 rnd(22);

void quickSort(int *a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int pivotInd = rnd()%(r - l + 1) + l;

    int smallerCnt = 0;
    for (int i = l; i <= r; i++)
    {
        if (a[i] < a[pivotInd])
        {
            smallerCnt++;
        }
    }

    swap(a[pivotInd], a[smallerCnt + l]);
    pivotInd = smallerCnt + l;

    int pivotEqualInd = pivotInd + 1;
    for (int i = l; i <= r; i++)
    {
        if (!(pivotInd <= i && i < pivotEqualInd) && a[i] == a[pivotInd])
        {
            swap(a[i], a[pivotEqualInd]);
            pivotEqualInd++;
        }
    }

    int indRight = pivotEqualInd;
    for (int i = pivotInd - 1; i >= l; i--)
    {
        if (a[i] > a[pivotInd])
        {
            while (a[indRight] >= a[pivotInd])
            {
                indRight++;
            }

            swap(a[i], a[indRight]);
            indRight++;
        }
    }

    quickSort(a, l, pivotInd - 1);
    quickSort(a, pivotEqualInd, r);
}

int n;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
