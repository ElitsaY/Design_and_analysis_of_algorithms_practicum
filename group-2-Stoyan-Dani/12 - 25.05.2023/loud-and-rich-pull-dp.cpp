class Solution {
public:
    int n;
    vector<vector<int>> adj, adjInv;

    void buildGraphs(vector<vector<int>>& richer)
    {
        adj.resize(n);
        adjInv.resize(n);

        for (const vector<int> &e : richer)
        {
            adj[e[0]].push_back(e[1]);
            adjInv[e[1]].push_back(e[0]);
        }
    }

    void dfs(int x, vector<bool> &used, vector<int> &topsort)
    {
        used[x] = true;
        for (int y : adj[x])
        {
            if (!used[y])
            {
                dfs(y, used, topsort);
            }
        }

        topsort.push_back(x);
    }

    void buildTopsort(vector<int> &topsort)
    {
        vector<bool> used(n, false);

        for (int x = 0; x < n; x++)
        {
            if (!used[x])
            {
                dfs(x, used, topsort);
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n = quiet.size();
        buildGraphs(richer);

        vector<int> topsort;
        buildTopsort(topsort);

        vector<int> dp(n);
        reverse(topsort.begin(), topsort.end());

        for (int x : topsort)
        {
            dp[x] = x;
            for (int y : adjInv[x])
            {
                if (quiet[dp[y]] < quiet[dp[x]])
                {
                    dp[x] = dp[y];
                }
            }
        }

        return dp;
    }
};
