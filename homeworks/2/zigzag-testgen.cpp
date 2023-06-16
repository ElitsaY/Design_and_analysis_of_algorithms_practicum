//0 -> testgen
//1 -> wrong solition
//2 -> correct solution
//3 -> testcase splitter
#define MODE 0

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

const int MAX_N = 1e5;
const int MAX_M = 1e6;
const int64_t inf = 1e17;

mt19937_64 rnd((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int64_t randInRange(int64_t l, int64_t r)
{
    return l + rnd() % (r - l + 1);
}

template < typename T > std::string to_string(const T& n)
{
    std::ostringstream stm;

    stm << n;
    return stm.str();
}

struct Graph
{
    int n, m;
    vector<pair<int, int>> adj[MAX_N + 5];

    struct State
    {
        int x;
        bool lastDirection;

        State() {}
        State(int x, bool lastDirection) : x(x), lastDirection(lastDirection) {}

        bool operator <(const State& other) const
        {
            if (x != other.x)
            {
                return x < other.x;
            }

            return lastDirection < other.lastDirection;
        }
    };


    Graph(int n) : n(n), m(0)
    {
    }

    void addEdge(int a, int b, int w)
    {
        m++;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }

    static bool getDirection(int a, int b)
    {
        return !(a < b);
    }

    int64_t solveCorrectly() const
    {
        vector<vector<int64_t>> dist(n + 1, vector<int64_t>(2, inf));
        priority_queue<pair<int64_t, State>, vector<pair<int64_t, State>>, greater<pair<int64_t, State>>> pq;

        dist[1][0] = dist[1][1] = 0;
        pq.emplace(0, State(1, 0));
        pq.emplace(0, State(1, 1));

        while (!pq.empty())
        {
            State st = pq.top().second;
            int64_t d = pq.top().first;
            pq.pop();

            if (d != dist[st.x][st.lastDirection])
            {
                continue;
            }

            if (st.x == n)
            {
                return d;
            }

            for (const pair<int, int>& e : adj[st.x])
            {
                if (getDirection(st.x, e.first) != st.lastDirection
                    && dist[e.first][getDirection(st.x, e.first)] > dist[st.x][st.lastDirection] + e.second)
                {
                    dist[e.first][getDirection(st.x, e.first)] = dist[st.x][st.lastDirection] + e.second;
                    pq.emplace(dist[e.first][getDirection(st.x, e.first)], State(e.first, getDirection(st.x, e.first)));
                }
            }
        }

        return -1;
    }

    int64_t solveIncorrectly() const
    {
        vector<int64_t> dist(n + 1, inf);
        vector<int> par(n + 1, MAX_N);

        priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

        dist[1] = 0;
        pq.emplace(0, 1);

        while (!pq.empty())
        {
            int x = pq.top().second;
            int64_t d = pq.top().first;

            pq.pop();

            if (dist[x] != d)
            {
                continue;
            }

            if (x == n)
            {
                return d;
            }

            for (const pair<int, int>& e : adj[x])
            {
                if (getDirection(par[x], x) != getDirection(x, e.first)
                    && dist[e.first] > dist[x] + e.second)
                {
                    dist[e.first] = dist[x] + e.second;
                    par[e.first] = x;

                    pq.emplace(dist[e.first], e.first);
                }
            }
        }

        return -1;
    }

    void dump(ostream& testFileIn, ostream& testFileOut)
    {
        testFileIn << n << " " << m << '\n';
        for (int x = 1; x <= n; x++)
        {
            for (const pair<int, int>& e : adj[x])
            {
                if (e.first > x)
                {
                    testFileIn << x << " " << e.first << " " << e.second << '\n';
                }
            }
        }

        testFileOut << solveCorrectly() << '\n';
    }
};

void testgen()
{
    int n = 1000000, m = 1000000;
    const int MAX_W = 1000000000;

    while (true)
    {
        Graph* G = new Graph(n);

        for (int i = 0; i < m; i++)
        {
            int a = randInRange(1, n);
            int b = randInRange(1, n);
            int w = randInRange(MAX_W / 1.5, MAX_W);

            G->addEdge(a, b, w);
        }

        if (G->solveCorrectly() != G->solveIncorrectly())
        {
            ofstream fileTestIn("test-13-in.txt");
            ofstream fileTestOut("test-13-out.txt");

            G->dump(fileTestIn, fileTestOut);

            break;
        }
        else
        {
            cout << "fail" << '\n';
        }

        delete G;
    }
}

void wrongSolution()
{
    int n, m;
    cin >> n >> m;

    Graph* G = new Graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        G->addEdge(a, b, w);
    }

    cout << G->solveIncorrectly() << '\n';
}

void correctSolution()
{
    int n, m;
    cin >> n >> m;

    Graph* G = new Graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;

        if (a != b)
        {
            G->addEdge(a, b, w);
        }
    }

    cout << G->solveCorrectly() << '\n';
}

void splitTestcases()
{
    int T;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        ofstream subcaseIn("subcase-" + to_string(t + 1) + ".in");

        int n, m;
        cin >> n >> m;

        subcaseIn << n << " " << m << '\n';
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;

            subcaseIn << a << " " << b << " " << w << '\n';
        }

        subcaseIn.close();
    }
}

int main()
{
#if MODE == 0
    testgen();
#elif MODE == 1
    wrongSolution();
#elif MODE == 2
    correctSolution();
#elif MODE == 3
    splitTestcases();
#endif
}
