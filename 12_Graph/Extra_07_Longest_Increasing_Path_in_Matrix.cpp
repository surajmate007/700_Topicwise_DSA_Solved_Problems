// I was too uch surprised when this question was solved by sarang in the contest🙁😳🤯

// Now my solution accepted in one go:

class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    
    int getAns(vector<vector<int>>& matrix, int i, int j, int n, int m, vector<vector<int>>& dp){
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 1;
        for(int k=0; k<4; k++){
            int x = i+dir[k]; int y = j+dir[k+1];
            if(x>=0 and y>=0 and x<n and y<m and matrix[x][y] > matrix[i][j]){
                ans = max(ans, 1 + getAns(matrix, x, y, n, m, dp));
            }
        }
        
        return dp[i][j] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, getAns(matrix, i, j, n, m, dp));
            }
        }
        
        return ans;
    }
};


// DP + DFS soution.

class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int dp[202][202];
    
    int getPath(int i, int j, int n, int m, vector<vector<int>>& a){
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        
        int ans = 1;
        for(int k=0; k<4; k++){
            int x = i+dx[k]; int y = j+dy[k];
            if(x<0 or x>=n or y<0 or y>=m or a[i][j] >= a[x][y]){
                continue;
            }
            else{
                int mx = 1 + getPath(x, y, n, m, a);
                ans = max(ans, mx);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); int m = matrix[0].size();
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans, getPath(i, j, n, m, matrix));
            }
        }
        
        return ans;
    }
};
