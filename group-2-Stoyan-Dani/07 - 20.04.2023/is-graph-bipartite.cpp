class Solution
{
public:

    void dfs(int x, bool c, vector<bool> &used, vector<bool> &color, const vector<vector<int>> &graph, bool &answer)
    {
        color[x] = c;
        used[x] = true;

        for (int y: graph[x])
        {
            if(!used[y])
            {
                dfs(y, c ^ 1, used, color, graph, answer);
            }
            else
            {
                if (color[y] == color[x])
                {
                    answer = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<bool> used(n, false);
        vector<bool> color(n, false);

        bool answer = true;
        for (int x = 0; x < n; x++)
        {
            if (!used[x])
            {
                dfs(x, false, used, color, graph, answer);
            }
        }

        return answer;
    }
};
