// it cant be solved using exact LCS approach because of the replace operation.
// But very close to LCS with minor chnages.

int editDistance(string s, string t){
        int n1 = s.length(), n2 = t.length();
        int dp[n1+1][n2+1];
        
        for(int i=0; i<=n1; i++){     
            dp[i][0] = i;             // filling with i because it will tell no. of deletions to get t from s.
        }
        for(int i=0; i<=n2; i++){     // filling with i because it will tell no. of insertions to get t from s.
            dp[0][i] = i;
        }
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];  // when chars are same then no operation needed.
                }
                else{
                    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});         // when different then look for min of operations.
                }
            }
        }
        return dp[n1][n2];
}
