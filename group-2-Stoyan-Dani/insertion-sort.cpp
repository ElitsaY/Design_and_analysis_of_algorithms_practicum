#include <iostream>

using namespace std;

const int MAXN = 100;

int n;
int a[MAXN + 5];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j - 1 >= 0 && a[j - 1] > a[j])
        {
            swap(a[j - 1], a[j]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
