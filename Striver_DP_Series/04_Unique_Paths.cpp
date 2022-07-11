// Recusrion:

class Solution {
public:
    
    int getAns(int n, int m, int i, int j){
        if(i>=n or j>=m){
            return 0;
        }
        
        if(i==n-1 and j==m-1){
            return 1;
        }
        
        int ans = 0;
        
        ans += getAns(n, m, i+1, j);
        ans += getAns(n, m, i, j+1);
            
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        return getAns(n, m, 0, 0);
    }
};


// Memoised:

class Solution {
public:
    
    int getAns(int n, int m, int i, int j, vector<vector<int>>& dp){
        if(i>=n or j>=m){
            return 0;
        }
        
        if(i==n-1 and j==m-1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        
        ans += getAns(n, m, i+1, j, dp);
        ans += getAns(n, m, i, j+1, dp);
            
        return dp[i][j] = ans;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getAns(m, n, 0, 0, dp);
    }
};


// Tabulation:



class Solution {
public:
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 or j==0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
