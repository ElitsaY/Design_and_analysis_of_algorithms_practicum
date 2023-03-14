#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1e6;
const int MAX_LEN = 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int cnt = 0;
    string mainCharacter;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (cnt == 0)
        {
            mainCharacter = s;
        }

        if (mainCharacter == s)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }

    cout << mainCharacter << '\n';
}
