// Easy solution.
// Most of the path finding problems use DP.
// Leetcode Problem no : 64

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        int n = grid.size(); int m = grid[0].size();
        
        for(int i=1; i<n; i++){
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        
        for(int j=1; j<m; j++){
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n-1][m-1];
    }
};
