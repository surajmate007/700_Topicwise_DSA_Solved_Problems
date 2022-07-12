// Recursive Code:

#include<bits/stdc++.h>

int getAns(vector<int>& wt, vector<int>& val, int n, int mwt, int idx){
    if(idx == n){
        return 0;
    }
    
    int cost1 = 0; int cost2 = 0;
    if(wt[idx] <= mwt){
        cost1 = val[idx] + getAns(wt, val, n, mwt-wt[idx], idx+1);
    }
    cost2 = getAns(wt, val, n, mwt, idx+1);
    
    return max(cost1, cost2);
}

int knapsack(vector<int> wt, vector<int> val, int n, int mwt){
	return getAns(wt, val, n, mwt, 0);
}


// Memoised :


#include<bits/stdc++.h>

int getAns(vector<int>& wt, vector<int>& val, int n, int mwt, int idx, vector<vector<int>>& dp){
    if(idx == n){
        return 0;
    }
    
    if(dp[idx][mwt] != -1){
        return dp[idx][mwt];
    }
    
    int cost1 = 0; int cost2 = 0;
    if(wt[idx] <= mwt){
        cost1 = val[idx] + getAns(wt, val, n, mwt-wt[idx], idx+1, dp);
    }
    cost2 = getAns(wt, val, n, mwt, idx+1, dp);
    
    return dp[idx][mwt] = max(cost1, cost2);
}

int knapsack(vector<int> wt, vector<int> val, int n, int mwt){
    vector<vector<int>> dp(n+1, vector<int> (mwt+1, -1));
	return getAns(wt, val, n, mwt, 0, dp);
}


// Tabulation:

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
