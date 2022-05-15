// here the logic is simple and exactly same as LCS:
// just the chages are when the characters are not matching then in LCS we used to take dp[i][j] = max(dp[i-1][j], dp[i][j-1]) but here
// if the characters are not matching we will take dp[i][j] = 0;
// Aso we will always keep track of maximum length of matched substring.

int longestCommonSubstr (string S1, string S2, int n, int m){
        int dp[n+1][m+1];
        int ans = 0;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{ 
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
}
