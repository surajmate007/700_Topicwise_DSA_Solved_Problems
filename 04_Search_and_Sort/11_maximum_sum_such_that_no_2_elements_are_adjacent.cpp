// Simple recursive approach for this problem. Written by myself:

int getsum(int arr[], int n, int idx, int ans){
    if(idx >= n){
        return ans;
    }
    return max(getsum(arr, n, idx+2, ans+arr[idx]), getsum(arr, n, idx+1, ans));
}
    
int FindMaxSum(int arr[], int n){
    return getsum(arr, n, 0, 0);
}

// Uisng DP but still giving TLE:

int FindMaxSum(int arr[], int n){
        if(n==1){
            return arr[0];
        }
        int dp[n]; 
        memset(dp, -1, sizeof(dp));
        dp[0] = arr[0]; dp[1] = arr[1];
        int ans = max(dp[0], dp[1]);
        
        for(int i=2; i<n; i++){
            for(int j=0; j<i-1; j++){
                dp[i] = max(dp[i], arr[i]+dp[j]);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
}

// with some mpre modifications in the code it gave an output:

int FindMaxSum(int arr[], int n){
        if(n==1){
            return arr[0];
        }
        int dp[n]; 
        memset(dp, -1, sizeof(dp));
        dp[0] = arr[0]; dp[1] = arr[1];
        int ans = max(dp[0], dp[1]);
        
        for(int i=2; i<n; i++){
            if(i-3 >= 0){
                dp[i] = arr[i] + max(dp[i-3], dp[i-2]);
            }
            else{
                dp[i] = arr[i] + dp[i-2];
            }
            
            ans = max(ans, dp[i]);
        }
        return ans;
}

// More optimal DP code:

int FindMaxSum(int arr[], int n){
        int dp[n]; 
        dp[0] = arr[0]; dp[1] = max(arr[0], arr[1]);
        
        
        for(int i=2; i<n; i++){
            int a = arr[i] + dp[i-2];
            int b = dp[i-1];
            dp[i] = max(a, b);
        }
        
        return dp[n-1];
}
