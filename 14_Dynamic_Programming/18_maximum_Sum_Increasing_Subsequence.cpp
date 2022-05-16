int maxSumIS(int arr[], int n){  
	    int dp[n];
	    for(int i=0; i<n; i++){
	        dp[i] = arr[i];
	    }
	    
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[j] < arr[i] and dp[i] < dp[j]+arr[i]){
	                dp[i] = dp[j] + arr[i];
	            }
	        }
	    }
	    
	    int ans = INT_MIN;
	    for(int i=0; i<n; i++){
	        ans = max(ans, dp[i]);
	    }
	   
	    return ans;
	}  
