#include <iostream>

using namespace std;

const int MAX_N = 1e6;
const int64_t inf = 1e15;

int n;
int h[MAX_N + 5];

int64_t answer = inf;

void rec(int ind, int64_t cost)
{
    if (ind == n - 1)
    {
        answer = min(answer, cost);
        return;
    }

    if (ind + 1 < n)
    {
        rec(ind + 1, cost + abs(h[ind] - h[ind + 1]));
    }
    if (ind + 2 < n)
    {
        rec(ind + 2, cost + abs(h[ind] - h[ind + 2]));
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    rec(0, 0);
    cout << answer << '\n';
}
