// combination of dfs and dp.

class Solution {
public:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    int mod = 1e9+7;
    
    int getAns(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int n, int m, long long& ans){
        
        if(dp[i][j] != 0){
            return dp[i][j];
        }
        
        long long mx=1;
        
        for(int k=0; k<4; k++){
            int x = dx[k]+i; int y = dy[k]+j;
            
            if(x<0 or y<0 or x>=n or y>=m or grid[i][j] >= grid[x][y]){
                continue;
            }
            else{
                long long val = getAns(grid, dp, x, y, n, m, ans)%mod;
                mx = (mx%mod + val%mod)%mod;
            }  
        }
        return dp[i][j] += mx;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        long long ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, 1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = (ans%mod + getAns(grid, dp, i, j, n, m, ans)%mod)%mod;
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return ans%mod;
    }
};
