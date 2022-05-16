// simple 1D array is needed. we will initialize first few indexes in array.
// then using the relation : dp[i] = dp[i-1] + (i-1) * dp[i-2]

long long const mod = 1e9 + 7;
    int countFriendsPairings(int n){ 
        long long dp[n + 1];
        memset(dp, -1, sizeof(dp));
        for (int i = 1;i < n + 1;i++) {
            if (i <= 2) dp[i] = i;
            else dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2]) % mod) % mod;
        }
        return dp[n];
}

// without memoization: but not working properly

long long const mod = 1e9 + 7;
    int countFriendsPairings(int n){ 
        if(n<=2){
            return n;
        }
        int prev1 = 1; int prev2 = 2;
        for(int i=3; i<=n; i++){
            int curr = (prev2 + ((i-1)*prev1)%mod)%mod;
            prev1 = prev2;
            prev2 = curr;
        }
        
        return prev1;
}
