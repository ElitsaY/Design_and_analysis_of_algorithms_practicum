#include <iostream>
#include <fstream>
#include <set>

using namespace std;

const int MAXN = 1e5;
const int inf = 1e9;

int n;
int64_t m;
int64_t f[MAXN + 5], s[MAXN + 5];

int main()
{
    ifstream fin("hayfeast.in");
    ofstream fout("hayfeast.out");

    ios::sync_with_stdio(false);
    fin.tie(nullptr);

    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        fin >> f[i] >> s[i];
    }

    int64_t sum = f[0];
    multiset<int> ms = {s[0]};

    int ptr = 1;
    int ans = inf;
    for (int i = 0; i < n; i++)
    {
        while(ptr < n && sum < m)
        {
            sum += f[ptr];
            ms.insert(s[ptr]);

            ptr++;
        }

        if (sum >= m)
        {
            ans = min(ans, *prev(ms.end()));
        }

        sum -= f[i];
        ms.erase(ms.find(s[i]));
    }

    fout << ans << '\n';
}
