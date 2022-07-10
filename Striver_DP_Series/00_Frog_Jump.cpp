// first did it recursively and then memoised it.

#include<bits/stdc++.h>

int getAns(vector<int>& heights, int n, int idx, vector<int>& dp){
    if(idx == n-1){
        return 0;
    }
    
    if(dp[idx] != -1){
        return dp[idx];
    }
    
    int one = INT_MAX, two = INT_MAX;
    
    if(idx < n-1){
        one = abs(heights[idx]-heights[idx+1]) + getAns(heights, n, idx+1, dp);
    }
    if(idx < n-2){
        two = abs(heights[idx]-heights[idx+2]) + getAns(heights, n, idx+2, dp);
    }
    
    return dp[idx] = min(one, two);
}

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n, -1);
    return getAns(heights, n, 0, dp);
}
