// Using Recursion:

#include<bits/stdc++.h>

int getAns(vector<int>& nums, int n, int tar, int idx){
    if(tar < 0){
        return 0;
    }
    
    if(idx == n){
        if(tar == 0){
            return 1;
        }
        return 0;
    }
    
    int count = 0;
    
    count += getAns(nums, n, tar-nums[idx], idx+1);
    count += getAns(nums, n, tar, idx+1);
    
    return count;
}

int findWays(vector<int> &num, int tar){
    int n = num.size();
    return getAns(num, n, tar, 0);
}


// Memoisation:

#include<bits/stdc++.h>

int getAns(vector<int>& nums, int n, int tar, int idx, vector<vector<int>>& dp){
    if(tar < 0){
        return 0;
    }
    
    if(idx == n){
        if(tar == 0){
            return 1;
        }
        return 0;
    }
    
    if(dp[idx][tar] != -1){
        return dp[idx][tar];
    }
    
    int count = 0;
    
    count += getAns(nums, n, tar-nums[idx], idx+1, dp);
    count += getAns(nums, n, tar, idx+1, dp);
    
    return dp[idx][tar] = count;
}

int findWays(vector<int> &num, int tar){
    int n = num.size();
    vector<vector<int>> dp(n+1, vector<int>(tar+1, -1));
    return getAns(num, n, tar, 0, dp);
}
