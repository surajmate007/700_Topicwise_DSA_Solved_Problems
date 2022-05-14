// topdown approach with one dimensional array.


int maximizeTheCuts(int n, int x, int y, int z){
        vector<int> dp(n+1, -1); dp[0]=0;
        for(int i=1; i<=n; i++){
            if(x<=i){dp[i] = max(dp[i], dp[i-x]);}
            if(y<=i){dp[i] = max(dp[i], dp[i-y]);}
            if(z<=i){dp[i] = max(dp[i], dp[i-z]);}
            if(dp[i] != -1){
                dp[i]++;
            }
        }
        
        return max(dp[n],0);
}
