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
        int bestInd = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[bestInd])
            {
                bestInd = j;
            }
        }

        swap(a[i], a[bestInd]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
}
