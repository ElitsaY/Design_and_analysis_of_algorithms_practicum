#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 1e5;

struct Block
{
    int64_t pos;
    int64_t amount;

    Block(){}
    Block(int64_t pos, int64_t amount) : pos(pos), amount(amount) {}
};

int n;
Block a[MAXN + 5];
Block aCpy[MAXN + 5];

bool check(int64_t baseAmount)
{
    stack <int> waiting;
    for (int i = 0; i < n; i++)
    {
        if (a[i].amount > baseAmount)
        {
            int lastPos = a[i].pos;
            while(!waiting.empty())
            {
                a[i].amount -= (lastPos - a[waiting.top()].pos) + (baseAmount - a[waiting.top()].amount);
                a[waiting.top()].amount = baseAmount;

                lastPos = a[waiting.top()].pos;
                waiting.pop();
            }

            if (i + 1 < n && a[i].amount - (a[i + 1].pos - a[i].pos) >= baseAmount && i + 1 < n)
            {
                a[i + 1].amount += a[i].amount - baseAmount - (a[i + 1].pos - a[i].pos);
                a[i].amount = baseAmount;
            }
            else if (a[i].amount < baseAmount)
            {
                waiting.push(i);
            }
        }
        else if (a[i].amount < baseAmount)
        {
            waiting.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = aCpy[i];
    }

    return waiting.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].pos >> a[i].amount;
        aCpy[i] = a[i];
    }
    sort(a, a + n, [](const Block &A, const Block &B)
    {
        if (A.pos != B.pos) return A.pos < B.pos;
        return A.amount < B.amount;
    });

    int64_t l = 0, r = 1e15, mid;
    while (l + 1 < r)
    {
        mid = (l + r) / 2;

        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    if (check(r))
    {
        cout << r << '\n';
    }
    else
    {
        cout << l << '\n';
    }
}
