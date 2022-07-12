// Recursive Code:


bool getAns(vector<int>& arr, int n, int tar, int idx, int sum){
    if(sum > tar){
        return false;
    }
    
    if(idx == n){
        if(sum == tar){
            return true;
        }
        return false;
    }
    
    bool ans = getAns(arr, n, tar, idx+1, sum+arr[idx]) or getAns(arr, n, tar, idx+1, sum);
    
    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    return getAns(arr, n, k, 0, 0);
}


// Memoised:


#include<bits/stdc++.h>

bool getAns(vector<int>& arr, int n, int tar, int idx, vector<vector<int>>& dp){
    if(tar < 0){
        return false;
    }
    
    if(idx == n){
        if(tar == 0){
            return true;
        }
        return false;
    }
    
    if(dp[idx][tar] != -1){
        return dp[idx][tar];
    }
    
    bool ans = getAns(arr, n, tar-arr[idx], idx+1, dp) or getAns(arr, n, tar, idx+1, dp);
    
    return dp[idx][tar] = ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return getAns(arr, n, k, 0, dp);
}


