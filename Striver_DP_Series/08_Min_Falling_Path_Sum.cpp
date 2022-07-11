// Recursive:

class Solution {
public:
    
    int getAns(vector<vector<int>>& matrix, int n, int i, int j){
        if(j<0 or j>=n){
            return INT_MAX;
        }
        
        if(i==n){
            return 0;
        }
        
        int cost = matrix[i][j];
        cost += min({getAns(matrix, n, i+1, j-1), getAns(matrix, n, i+1, j), getAns(matrix, n, i+1, j+1)});
                     
        return cost;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        
        for(int j=0; j<n; j++){
            ans = min(ans, getAns(matrix, n, 0, j));
        }
        
        return ans;
    }
};


// Memoised:


class Solution {
public:
    
    int getAns(vector<vector<int>>& matrix, int n, int i, int j, vector<vector<int>>& dp){
        if(j<0 or j>=n){
            return INT_MAX;
        }
        
        if(i==n){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int cost = matrix[i][j];
        cost += min({getAns(matrix, n, i+1, j-1, dp), getAns(matrix, n, i+1, j, dp), getAns(matrix, n, i+1, j+1, dp)});
                     
        return dp[i][j] = cost;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        for(int j=0; j<n; j++){
            ans = min(ans, getAns(matrix, n, 0, j, dp));
        }
        
        return ans;
    }
};


// Tabulation:



class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int omin = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n,-1));
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++){
            omin = min(omin, matrix[0][i]);
            dp[0][i] = matrix[0][i];
        }
        
        if(n==1){
            return omin;
        }
        
        for(int i=1; i<n; i++){
            
            for(int j=0; j<n; j++){
                int a=INT_MAX, b=INT_MAX, c=INT_MAX;
                b = dp[i-1][j];
                
                if(j>0){
                    a = dp[i-1][j-1];
                }
                if(j<n-1){
                    c = dp[i-1][j+1];
                }
                
                dp[i][j] = matrix[i][j] + min({a, b, c});
                
                if(i==n-1){
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};
