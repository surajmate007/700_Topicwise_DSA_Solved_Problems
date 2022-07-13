// Recursive:

#include<bits/stdc++.h>

int getAns(int n, int w, int idx, vector<int>& val, vector<int>& wt){
    
    if(idx == n){
        return 0;
    }
    
    int ans1 = 0; int ans2 = 0;
    
    if(wt[idx] <= w){
        ans1 = val[idx] + getAns(n, w-wt[idx], idx, val, wt);
    }
    
    ans2 = getAns(n, w, idx+1, val, wt);
    
    return max(ans1, ans2);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return getAns(n, w, 0, profit, weight);
}


// Memoised:


#include<bits/stdc++.h>

int getAns(int n, int w, int idx, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
    
    if(idx == n){
        return 0;
    }
    
    if(dp[idx][w] != -1){
        return dp[idx][w];
    }
    
    int ans1 = 0; int ans2 = 0;
    
    if(wt[idx] <= w){
        ans1 = val[idx] + getAns(n, w-wt[idx], idx, val, wt, dp);
    }
    
    ans2 = getAns(n, w, idx+1, val, wt, dp);
    
    return dp[idx][w] = max(ans1, ans2);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    return getAns(n, w, 0, profit, weight, dp);
}

