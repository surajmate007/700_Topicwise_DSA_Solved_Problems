// same approach of finding the longest subsequence only mention this specific condition whicle updating the dp array.


int longestSubsequence(int N, int arr[]){
        if(N==1){
            return 1;
        }
        int dp[N+1];
        int ans = 0;
        for(int i=0; i<N; i++){
            dp[i] = 1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<i; j++){
                if(abs(arr[j]-arr[i])==1){
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
}
