#include <iostream>
#include <vector>

using namespace std;

int n, m, t;

vector<int> a, b, c;

void merge()
{

    int a_idx = 0, b_idx = 0;
    while(a_idx < a.size() && b_idx < b.size())
    {

        if(a[a_idx] < b[b_idx])
        {
            c.push_back(a[a_idx]);
            a_idx++;
        }
        else
        {
            c.push_back(b[b_idx]);
            b_idx++;
        }
    }
    while(a_idx < a.size())
    {
        c.push_back(a[a_idx]);
        a_idx++;
    }
    while(b_idx < b.size())
    {
        c.push_back(b[b_idx]);
        b_idx++;
    }
    return ;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> t;
        b.push_back(t);
    }

    merge();

    for(int i = 0; i < c.size(); i++)
    {

        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
