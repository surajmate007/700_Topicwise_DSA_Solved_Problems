// simple solution based on floyd warshall algorithm.

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        int inf = 1e9+7;
        
        vector<vector<int>> start(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    start[i][j] = 0;
                }
                else{
                    start[i][j] = inf;
                }
            }
        }
        
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0]; int b = edges[i][1]; int c = edges[i][2];
            start[a][b] = c;
            start[b][a] = c;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j] = min(start[i][j], start[i][k]+start[k][j]);
                }
            }
            start = dp;
        }
        
        int ans = 0;
        int mcnt = INT_MAX;
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(start[i][j] <= dt and i!=j){
                    cnt++;
                } 
            }
            if(cnt <= mcnt){
                mcnt = cnt;
                ans = i;
            }
        }
        
        return ans;
    }
};
