// Leetcode problem : 120
// This is the recursive code for this problem:
class Solution {
public:
    void getPath(vector<vector<int>> triangle, int n, int& ans, int sum, int i, int j){
        if(i==n){
            ans = min(ans, sum);
            return;
        }
        
        if(j>i){
            return;
        }
        
        getPath(triangle, n, ans, sum + triangle[i][j], i+1, j);
        
        getPath(triangle, n, ans, sum + triangle[i][j], i+1, j+1);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int ans = INT_MAX; int sum = 0;
        getPath(triangle, n, ans, sum, 0, 0);
        
        return ans;
    }
};


// Thhs is the dp approach using top down:

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
