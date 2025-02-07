// simple using 2d dp approach:

int productSubSeqCount(vector<int> &arr, int k){
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
    
            // number of subsequence using j-1 terms
            dp[i][j] = dp[i][j - 1];
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i)
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }
    return dp[k][n];
}


// similar version of simple code that we used to see in 0-1 knapsack problem:

int productSubSeqCount(vector<int> &arr, int k){
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++){
   
            // if arr[j-1] > i it will surely make product greater
            // thus it won't contribute then
            if (arr[j - 1] <= i){
 
                // number of subsequence using 1 to j-1 terms
                // and j-th term
                dp[i][j] = 1 + dp[i/arr[j-1]][j-1] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
        }
    }
    return dp[k][n];
}
