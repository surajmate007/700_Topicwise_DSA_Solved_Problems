// this is recursice solution for 0-1 knapsack problem but gives TLE:

int knapSack(int W, int wt[], int val[], int n) { 
        if(W==0 or n==0){
            return 0;
        }
        if(wt[n-1] <= W){
            return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        }
        else{
            return knapSack(W, wt, val, n-1);
        }
    }

// This solution is using Dynamic Programming without topdown approach it also gives TLE:

int dp[1002][1002];
    
    int knapsackdp(int W, int wt[], int val[], int n){
        if(n==0 or W==0){
            return 0;
        }
        if(dp[n][W] != -1){
            return dp[n][W];
        }
        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1]+knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1));
        }
        else{
            return dp[n][W] = knapSack(W, wt, val, n-1);
        }
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
        memset(dp, -1, sizeof(dp));
        return knapsackdp(W, wt, val, n);
 }

// This is top down solution for this problem it does not give TLE:

int knapSack(int W, int wt[], int val[], int n) { 
        int dp[n+1][W+1];
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=W; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(wt[i-1] <= j){
                    dp[i][j] = max((val[i-1] + dp[i-1][j-wt[i-1]]), dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }



