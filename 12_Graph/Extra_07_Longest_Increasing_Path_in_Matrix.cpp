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
