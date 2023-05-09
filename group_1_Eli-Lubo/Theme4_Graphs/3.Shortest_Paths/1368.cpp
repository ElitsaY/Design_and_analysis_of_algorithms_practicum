/**
 * @author Lyuben Georgiev
 * @brief Problem: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/
 * @date 27/04/2023
 * 
*/

const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};
class Solution {
public:

    int minCost(vector<vector<int>>& grid) {
        int cost[101][101], n = grid.size(), m = grid[0].size();
        bool vis[101][101] = {{false,},};
        for (int i = 0; i < n; ++i)
        {
            fill(&cost[i][0], &cost[i][0] + m, 1000000000);
        }

        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        cost[0][0] = 0;

        while (!dq.empty())
        {
            const auto [x, y] = dq.front();
            dq.pop_front();

            vis[x][y] = true;

            for (int i = 1; i <= 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY] &&
                    (cost[x][y] + (grid[x][y] != i) < cost[newX][newY]))
                {
                    if (grid[x][y] == i)
                    {
                        dq.push_front({newX, newY});
                    }
                    else
                    {
                        dq.push_back({newX, newY});
                    }
                    cost[newX][newY] = cost[x][y] + (grid[x][y] != i);
                }
            }
        }

        return cost[n-1][m-1];
    }
};