#include <iostream>
#include <random>

using namespace std;

mt19937 rnd(22);

void addAll(vector <int> &dest, const vector <int> &source)
{
    for (int x : source)
    {
        dest.push_back(x);
    }
}

vector <int> quickSort(const vector <int> &v)
{
    if (v.size() <= 1)
    {
        return v;
    }

    int pivotInd = rnd() % v.size();

    int equalCnt = 0;
    vector <int> smaller, bigger;
    for (int x : v)
    {
        if (x < v[pivotInd])
        {
            smaller.push_back(x);
        }
        else if (x == v[pivotInd])
        {
            equalCnt++;
        }
        else
        {
            bigger.push_back(x);
        }
    }

    vector <int> ans = quickSort(smaller);
    for (int i = 0; i < equalCnt; i++)
    {
        ans.push_back(v[pivotInd]);
    }
    addAll(ans, quickSort(bigger));

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    v = quickSort(v);
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << '\n';
}
