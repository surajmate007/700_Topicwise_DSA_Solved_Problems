// Recursion:


class Solution {
public:
    
    int getAns(string x, string y, int n, int m, int idx1, int idx2){
        if(idx1 >= n or idx2 >= m){
            return 0;
        }
        
        int ans = 0;
        
        if(x[idx1] == y[idx2]){
            ans = 1 + getAns(x, y, n, m, idx1+1, idx2+1);
        }
        else{
            int first = 0, second = 0;
            first = getAns(x, y, n, m, idx1+1, idx2);
            second = getAns(x, y, n, m, idx1, idx2+1);
            ans = max(first, second);
        }
        
        return ans;
    }
    
    int longestCommonSubsequence(string X, string Y) {
        int n = X.length(); int m = Y.length();
        return getAns(X, Y, n, m, 0, 0);
    }
};


// Memoised:

class Solution {
public:
    
    int getAns(string& x, string& y, int n, int m, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n or idx2 >= m){
            return 0;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        int ans = 0;
        
        if(x[idx1] == y[idx2]){
            ans = 1 + getAns(x, y, n, m, idx1+1, idx2+1, dp);
        }
        else{
            int first = 0, second = 0;
            first = getAns(x, y, n, m, idx1+1, idx2, dp);
            second = getAns(x, y, n, m, idx1, idx2+1, dp);
            ans = max(first, second);
        }
        
        return dp[idx1][idx2] = ans;
    }
    
    int longestCommonSubsequence(string X, string Y) {
        int n = X.length(); int m = Y.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return getAns(X, Y, n, m, 0, 0, dp);
    }
};


// Tabulation:

class Solution {
public:
    
    int longestCommonSubsequence(string X, string Y) {
        int n = X.size();
        int m = Y.size();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(X[i-1] == Y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
