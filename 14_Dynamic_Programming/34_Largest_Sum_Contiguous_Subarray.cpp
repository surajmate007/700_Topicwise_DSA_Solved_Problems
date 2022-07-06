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



// using DP:


class Solution{
public:	
	int maxSubstring(string s){
	    int n = s.length();
	    int arr[n];
	    
	    for(int i=0; i<n; i++){
	        if(s[i] == '0'){
	            arr[i] = 1;
	        }
	        else{
	            arr[i] = -1;
	        }
	    }
	    
	    int dp[n];
	    dp[0] = max(arr[0], 0);
	    int ans = dp[0];
	    
	    for(int i=1; i<n; i++){
	        dp[i] = max(arr[i], dp[i-1] + arr[i]);
	        ans = max(ans, dp[i]);
	    }
	    
	    if(ans == 0){
	        return -1;
	    }
	    return ans;
	}
};
