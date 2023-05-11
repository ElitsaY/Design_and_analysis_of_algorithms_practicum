    /**
     * @author Lyuben Georgiev
     * @brief Problem: https://action.informatika.bg/problems/133
     * @date 11/05/2023
     * 
    */

    #include <cstdio>
    #include <queue>
    #include <vector>
    #include <algorithm>

    const int MOD = 1000000007;

    using Pair = std::pair<int, int>;
    using LPair = std::pair<long long, int>;

    const long long INF = 1e15;
    const int SOURCE = 1;

    int n, m;
    std::vector<Pair> adjList[100001];
    bool visited[100001];
    long long dists[100001];
    int paths[100001];

    int main()
    {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
        {
            int u, v, t;
            scanf("%d %d %d", &u, &v, &t);

            adjList[u].push_back({v, t});
        }

        std::fill(dists, dists + n + 1, INF);
        std::priority_queue<LPair, std::vector<LPair>, std::greater<LPair>> pq;
        pq.push({0, SOURCE});
        dists[SOURCE] = 0LL;
        paths[SOURCE] = 1;

        while (!pq.empty())
        {
            auto [curDist, u] = pq.top();
            pq.pop();

            if (visited[u])
                continue;
            visited[u] = true;

            for (const auto &[v, dist] : adjList[u])
            {
                if (!visited[v] && curDist + dist < dists[v])
                {
                    dists[v] = curDist + (long long)dist;
                    pq.push({dists[v], v});
                    paths[v] = paths[u];
                }
                else if (!visited[v] && curDist + dist == dists[v])
                {
                    paths[v] += paths[u];
                    paths[v] %= MOD;
                }
            }
        }

        if (dists[n] == INF)
        {
            printf("-1 0\n");
            return 0;
        }

        printf("%lld %d\n", dists[n], paths[n]);

        return 0;
    }