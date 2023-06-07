#include <iostream>
#include <cstring>
#include <fstream>
#include <array>

using namespace std;

const int MAXN = 1e5;
const int MAXK = 20;
const array<int, 3> beats = {2, 0, 1};

int encode(char c)
{
    if (c == 'H')
    {
        return 0;
    }
    if (c == 'P')
    {
        return 1;
    }
    if (c == 'S')
    {
        return 2;
    }
}

int n;
int a[MAXN + 5];

int memo[MAXN + 5][3][MAXK + 5];
int rec(int ind, int gesture, int changes)
{
    if (ind == n)
    {
        return 0;
    }
    if (memo[ind][gesture][changes] != -1)
    {
        return memo[ind][gesture][changes];
    }

    int ans = 0;
    if (changes > 0)
    {
        for (int newGesture = 0; newGesture < 3; newGesture++)
        {
            ans = max(ans, rec(ind, newGesture, changes - 1));
        }
    }

    if (beats[gesture] == a[ind])
    {
        ans = max(ans, 1 + rec(ind + 1, gesture, changes));
    }
    else
    {
        ans = max(ans, rec(ind + 1, gesture, changes));
    }

    memo[ind][gesture][changes] = ans;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream cin("hps.in");
    ofstream cout("hps.out");

    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;

        a[i] = encode(c);
    }

    memset(memo, -1, sizeof(memo));

    int ans = 0;
    for (int gesture = 0; gesture < 3; gesture++)
    {
        ans = max(ans, rec(0, gesture, k));
    }

    cout << ans << '\n';
}
