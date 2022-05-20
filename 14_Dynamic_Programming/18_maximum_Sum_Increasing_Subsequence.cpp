int maxSumIS(int arr[], int n){  
	    int dp[n];
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        dp[i] = arr[i];
	    }
	    
	    
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[j] < arr[i]){
	                dp[i] = max(dp[i], dp[j] + arr[i]);
			ans = max(ans, dp[i]);
	            }
	        }
	    }
	    return ans;
}  
