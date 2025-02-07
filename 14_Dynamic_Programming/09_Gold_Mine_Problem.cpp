// simple recursive approach with memoization:

int dp[1001][1001];
int recur(vector<vector<int>> gold, int x, int y, int m, int n) {
    if (x < 0 || y < 0 || x >= m || y >= n) return 0;

    return gold[x][y] + max({ recur(gold, x + 1, y + 1, m, n), recur(gold, x, y + 1, m, n), recur(gold, x - 1, y + 1, m, n) });
}

int getMaxGold(vector<vector<int>> gold, int m, int n) {
    int ans = INT_MIN;
    for (int i = 0;i < m;i++) {
        ans = max(ans, recur(gold, i, 0, m, n));
    }
    return ans;
}

// Another solution with dp:

int maxGold(int n, int m, vector<vector<int>> M){
        vector<vector<int>> dp(n + 2, vector<int>(m));

        for (int c = 0; c < m; ++c)
        	for (int r = 0; r < n; ++r)
        		dp[r + 1][c] = M[r][c] + max({dp[r][c - 1], dp[r + 1][c - 1], dp[r + 2][c - 1]});
        
        int ret = 0;
        for (int r = 0; r < n + 2; ++r)
        	ret = max(ret, dp[r][m - 1]);
        	
        return ret;
}


// Easiest Solution which I understood similar to Min Cost Path Problem:

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M){
        int dp[n][m];
        int omax = 0;
        for(int i=0; i<n; i++){
            dp[i][0] = M[i][0];
            omax = max(omax, M[i][0]);
        }
        
        for(int j=1; j<m; j++){
            for(int i=0; i<n; i++){
                int a = 0; int b = dp[i][j-1]; int c=0;
                if(i > 0){ a = dp[i-1][j-1];}
                if(i < n-1){ c = dp[i+1][j-1];}
                
                dp[i][j] = M[i][j] + max({a, b, c});
                omax = max(omax, dp[i][j]);
            }
        }
        return omax;
    }
};

