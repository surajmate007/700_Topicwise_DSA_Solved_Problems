// return len(string) - len(lps)

#include<bits/stdc++.h>

int minInsertion(string &str){
    string rev = str;
    reverse(rev.begin(), rev.end());
    int n = str.length();
    int dp[n+1][n+1];
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
            else if(str[i-1] == rev[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int len = dp[n][n];
    
    return n-len;
}
