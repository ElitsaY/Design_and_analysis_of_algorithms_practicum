class Solution {
public:
    int dp[128][128];
    int uniquePaths(int m, int n) {
        if(dp[m][n] != 0)return dp[m][n];
        if(m < 1 || n < 1)return 0;
        if(m == 1 && n == 1)return 1;
        int ans = uniquePaths(m, n - 1) + uniquePaths(m - 1, n);

        return dp[m][n] = ans;
    }
};
