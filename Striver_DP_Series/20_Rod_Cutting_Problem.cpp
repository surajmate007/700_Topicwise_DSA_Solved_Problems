// Recursive:


#include<bits/stdc++.h>

int getAns(vector<int>& val, int n, int idx){
    if(idx > n){
        return 0;
    }
    
    int ans1 = 0; int ans2 = 0;
    
    if(idx <= n){
        ans1 = val[idx-1] + getAns(val, n-idx, idx);
    }
    ans2 = getAns(val, n, idx+1);
    
    return max(ans1, ans2);
}

int cutRod(vector<int> &price, int n){
    return getAns(price, n, 1);
}



// Memoised:


#include<bits/stdc++.h>

int getAns(vector<int>& val, int n, int idx, vector<vector<int>>& dp){
    if(idx > n){
        return 0;
    }
    
    if(dp[idx][n] != -1){
        return dp[idx][n];
    }
    
    int ans1 = 0; int ans2 = 0;
    
    if(idx <= n){
        ans1 = val[idx-1] + getAns(val, n-idx, idx, dp);
    }
    ans2 = getAns(val, n, idx+1, dp);
    
    return dp[idx][n] = max(ans1, ans2);
}

int cutRod(vector<int> &price, int n){
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return getAns(price, n, 1, dp);
}

