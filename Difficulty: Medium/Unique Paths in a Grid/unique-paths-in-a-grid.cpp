
class Solution {
  public: //code written by sunny
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        dp[0][0] = 1; 
        for (int j = 1; j < m; j++) {
            if (grid[0][j] == 0) dp[0][j] = dp[0][j-1];
        }
 
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 0) dp[i][0] = dp[i-1][0];
        }
 
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};
 