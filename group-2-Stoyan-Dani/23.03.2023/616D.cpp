#include <iostream>
#include <map>

using namespace std;

struct Multiset
    {
        map <int, int> valCnt;

        int sizeUnique() const
        {
            return valCnt.size();
        }

        void add(int x)
        {
            valCnt[x]++;
        }

        void remove(int x)
        {
            if (valCnt.count(x))
            {
                valCnt[x]--;
                if (valCnt[x] == 0)
                {
                    valCnt.erase(x);
                }
            }
        }
    };

const int MAXN = 5e5;

int n, k;
int a[MAXN + 5];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ptr = 0;
    Multiset ms;
    ms.add(a[0]);

    int l = 0, r = -1;
    for (int i = 0; i < n; i++)
    {
        while (ptr < n && ms.sizeUnique() <= k)
        {
            ptr++;
            if (ptr < n)
            {
                ms.add(a[ptr]);
            }
        }

        //rollback one step
        if (ptr < n)
        {
            ms.remove(a[ptr]);
        }
        ptr--;

        if (ptr - i + 1 > r - l + 1)
        {
            l = i;
            r = ptr;
        }

        ms.remove(a[i]);
    }

    cout << l + 1 << " " << r + 1 << '\n';
}
