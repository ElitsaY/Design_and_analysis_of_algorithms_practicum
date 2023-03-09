#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 100;

void countSort(vector <int> &a)
{
    vector <int> cnt(MAX_VAL + 1, 0);

    for (int x : a)
    {
        cnt[x]++;
    }

    int ptr = 0;
    for (int x = 0; x <= MAX_VAL; x++)
    {
        for (int i = 0; i < cnt[x]; i++)
        {
            a[ptr] = x;
            ptr++;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    countSort(a);

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << '\n';
}
