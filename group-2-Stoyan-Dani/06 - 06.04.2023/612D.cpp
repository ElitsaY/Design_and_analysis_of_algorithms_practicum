#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Event
{
    int pos;
    bool type;

    Event(){}
    Event(int pos, bool type) : pos(pos), type(type) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<Event> events;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        events.emplace_back(l, false);
        events.emplace_back(r, true);
    }

    sort(events.begin(), events.end(),
    [](const Event &A, const Event &B)
    {
        if (A.pos != B.pos) return A.pos < B.pos;
        return A.type < B.type;
    });

    vector<pair<int, int>> answer;

    int balance = 0;
    int startSatisfied;
    for (const Event &e : events)
    {
        if (e.type == false)
        {
            balance++;
            if (balance == k)
            {
                startSatisfied = e.pos;
            }
        }
        else
        {
            balance--;
            if (balance == k - 1)
            {
                answer.emplace_back(startSatisfied, e.pos);
            }
        }
    }

    cout << answer.size() << '\n';
    for (const pair<int, int> &item: answer)
    {
        cout << item.first << " " << item.second << '\n';
    }
}
