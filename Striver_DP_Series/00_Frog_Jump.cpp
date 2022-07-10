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


// Tabulation:

#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights){
    vector<int> dp(n+1, -1);
    dp[n-1] = 0;
    
    int one = INT_MAX, two = INT_MAX;
    
    for(int i=n-2; i>=0; i--){
        one = dp[i+1] + abs(heights[i] - heights[i+1]);
        if(i<n-2){
            two = dp[i+2] + abs(heights[i] - heights[i+2]);
        }
        dp[i] = min(one, two);
    }
    
    return dp[0];
}


// space optimisation:
// since we are using only last 2 values of dp array.

#include<bits/stdc++.h>

int frogJump(int n, vector<int> &heights){
    int fst = 0, snd = 0;
    int one = INT_MAX, two = INT_MAX;
    
    for(int i=n-2; i>=0; i--){
        one = fst + abs(heights[i] - heights[i+1]);
        
        if(i<n-2){
            two = snd + abs(heights[i] - heights[i+2]);
        }
        
        snd = fst;
        fst = min(one, two);
    }
    
    return fst;
}
