// Recursive code:

#include<bits/stdc++.h>

int getAns(vector<int>& nums, int n, int idx){
    if(idx >= n){
        return 0;
    }
    
    int sum = max(nums[idx] + getAns(nums, n, idx+2), getAns(nums, n, idx+1));
    
    return sum;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    return getAns(nums, n, 0);
}

// Memoised :

#include<bits/stdc++.h>

int getAns(vector<int>& nums, int n, int idx, vector<int>& dp){
    if(idx >= n){
        return 0;
    }
    
    if(dp[idx] != -1){
        return dp[idx];
    }
    
    int include = nums[idx] + getAns(nums, n, idx+2, dp);
    int exclude = getAns(nums, n, idx+1, dp);
    
    return dp[idx] = max(include, exclude);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n+1, -1);
    return getAns(nums, n, 0, dp);
}


// Tabulation:

#include<bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    
    for(int i=2; i<n; i++){
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }
    
    return dp[n-1];
}


// House Robber Modificatoin:

// Memoised
class Solution {
public:
    
    int getAns(vector<int>& nums, int idx, vector<int>& dp){
        if(idx >= nums.size()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int rob = nums[idx] + getAns(nums, idx+2, dp);
        int notrob = getAns(nums, idx+1, dp);
        
        return dp[idx] = max(rob, notrob);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return getAns(nums, 0, dp);
    }
};


// House Robber 2:


class Solution {
public:
    
    int getAns(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec1, vec2;
        
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        
        vec1.push_back(nums[0]);
        for(int i=1; i<n-1; i++){
            vec1.push_back(nums[i]);
            vec2.push_back(nums[i]);
        }
        vec2.push_back(nums[n-1]);
        
        int ans1 = getAns(vec1);
        int ans2 = getAns(vec2);
        
        return max(ans1, ans2);
    }
};
