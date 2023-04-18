#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e5;

int n;
int a[MAXN + 5];

int64_t solveNonPositive(vector <int>& nonPositive)
{
    sort(nonPositive.begin(), nonPositive.end());

    int64_t ans = 0;
    for (int i = 0; i < nonPositive.size(); i += 2)
    {
        if (i + 1 < nonPositive.size())
        {
            ans += nonPositive[i] * 1LL * nonPositive[i + 1];
        }
        else
        {
            ans += nonPositive[i];
        }
    }

    return ans;
}

int64_t solveBiggerThan1(vector <int>& biggerThan1)
{
    sort(biggerThan1.begin(), biggerThan1.end(), greater <int> ());

    int64_t ans = 0;
    for (int i = 0; i < biggerThan1.size(); i += 2)
    {
        if (i + 1 < biggerThan1.size())
        {
            ans += biggerThan1[i] * 1LL * biggerThan1[i + 1];
        }
        else
        {
            ans += biggerThan1[i];
        }
    }

    return ans;
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

    vector <int> nonPositive;
    vector <int> biggerThan1;
    int ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= 0)
        {
            nonPositive.push_back(a[i]);
        }
        else if (a[i] == 1)
        {
            ones++;
        }
        else
        {
            biggerThan1.push_back(a[i]);
        }
    }

    cout << solveNonPositive(nonPositive) + ones + solveBiggerThan1(biggerThan1) << '\n';
}
