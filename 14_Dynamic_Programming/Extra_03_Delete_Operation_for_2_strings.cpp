// This is the DP based solution solved by me.
// Hence it is concluded that revision is important.


class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length();  int m = s2.length();
        int dp[n+1][m+1];
        
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                }
            }
        }
        
        return dp[n][m];
    }
};


// Another good approach for thius problem can be we will first find the LCS between both the strings and then 
                    (number of deletions = len1 + len2 - 2 * lenLCS)
