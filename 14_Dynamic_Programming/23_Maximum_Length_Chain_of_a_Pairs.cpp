// here they are asking about rearranging the pairs.
// hence we will sort them first based on the second value and the use LIS aproach.

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[], int n){
    sort(p, p+n, [](auto a, auto b){
        return a.second < b.second;
    });
    
    int dp[n];
    for(int i=0; i<n; i++){
        dp[i] = 1;
    }
    
    int ans = 1;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(p[j].second < p[i].first){
                dp[i] = max(dp[i], dp[j]+1);
                ans = max(ans, dp[i]);
            }
        }
    }
    
    // cout<<"cout : "<<dp[n-1]<<endl;
    
    return ans;
}
