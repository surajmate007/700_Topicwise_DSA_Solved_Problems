// Recursion:

class Solution {
public:
    
    int getAns(vector<vector<int>>& grid, int n, int m, int i, int j){
        if(i>=n or j>=m){
            return INT_MAX;
        }
        
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        
        int cost = grid[i][j];
        
        cost += min(getAns(grid, n, m, i+1, j), getAns(grid, n, m, i, j+1));
        
        return cost;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        
        return getAns(grid, n, m, 0, 0);
    }
};


// Memoisation:


class Solution {
public:
    
    int getAns(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i>=n or j>=m){
            return INT_MAX;
        }
        
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int cost = grid[i][j];
        
        cost += min(getAns(grid, n, m, i+1, j, dp), getAns(grid, n, m, i, j+1, dp));
        
        return dp[i][j] = cost;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return getAns(grid, n, m, 0, 0, dp);
    }
};



// Tabulation:

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
