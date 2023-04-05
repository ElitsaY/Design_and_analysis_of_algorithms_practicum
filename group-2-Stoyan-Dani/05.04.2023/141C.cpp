#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 3000;

struct Person
{
    string name;
    int invCnt;

    Person(){}
    Person(const string& name, int invCnt) : name(name), invCnt(invCnt) {}
};

int n;
Person a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].name >> a[i].invCnt;
    }
    sort(a, a + n,
    [](const Person& A, const Person& B)
    {
        return A.invCnt < B.invCnt;
    });

    vector <string> order;
    for (int i = 0; i < n; i++)
    {
        if (a[i].invCnt > i)
        {
            cout << "-1" << '\n';
            return 0;
        }

        order.insert(order.begin() + a[i].invCnt, a[i].name);
    }

    map <string, int> name2Height;
    for (int i = 0; i < order.size(); i++)
    {
        name2Height[order[i]] = n - i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << " " << name2Height[a[i].name] << '\n';
    }
}
