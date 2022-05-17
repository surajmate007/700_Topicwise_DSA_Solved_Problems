// simple kadanes algorithm:

long long maxSubarraySum(int arr[], int n){
        long long csum = arr[0]; long long osum = arr[0];
        for(int i=1; i<n; i++){
            if(osum < 0) osum = 0;
            osum += arr[i];
            if(csum < osum){
                csum = osum;
            }
        }
        return csum;
}

// using DP approach:

long long maxSubarraySum(int arr[], int n){
        long long dp[n];
        long long  omax;
        dp[0] = arr[0];
        omax = dp[0];
        for(int i=1; i<n; i++){
            dp[i] = max(dp[i-1] + arr[i], (long long)arr[i]);
            omax = max(omax, dp[i]);
        }
        
        return omax;
}
