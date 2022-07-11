// Recursion:

class Solution {
public:
    
    int getAns(vector<vector<int>>& tri, int row, int j){
        
        if(row == tri.size()){
            return 0;
        }
        
        int cost = tri[row][j];
        
        cost += min(getAns(tri, row+1, j), getAns(tri, row+1, j+1));
        
        return cost;
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return getAns(triangle, 0, 0);
    }
};


// Memoisation:


class Solution {
public:
    
    int getAns(vector<vector<int>>& tri, int row, int j, vector<vector<int>>& dp){
        
        if(row == tri.size()){
            return 0;
        }
        
        if(dp[row][j] != -1){
            return dp[row][j];
        }
        
        int cost = tri[row][j];
        
        cost += min(getAns(tri, row+1, j, dp), getAns(tri, row+1, j+1, dp));
        
        return dp[row][j] = cost;
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        for(int i=0; i<dp.size(); i++){
            for(int j=0; j<dp[i].size(); j++){
                dp[i][j] = -1;
            }
        }
        int n = triangle.size();
        
        return getAns(triangle, 0, 0, dp);
    }
};



// Tabulation:

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1){
            return triangle[0][0];
        }
        
        int ans = INT_MAX;
        vector<vector<int>> dp = triangle;
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==0){
                    dp[i][j] += dp[i-1][j];
                }
                else if(j==i){
                    dp[i][j] += dp[i-1][j-1];
                }
                else{
                    dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
                }
                
                if(i==n-1){
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};
