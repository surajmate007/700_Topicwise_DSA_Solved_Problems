// Recursive Code:

class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int tar, int idx, int sum1, int sum2){
        if(idx == n){
            if(sum1-sum2==tar){
                return 1;
            }
            return 0;
        }
        
        int ans1 = getAns(nums, n, tar, idx+1, sum1+nums[idx], sum2);
        int ans2 = getAns(nums, n, tar, idx+1, sum1, sum2+nums[idx]);
        
        return ans1 + ans2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return getAns(nums, n, target, 0, 0, 0);
    }
};


// Memoisation:


class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int tar, int idx, int sum1, int sum2, vector<vector<int>>& dp){
        if(idx == n){
            if(sum1-sum2==tar){
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][sum1] != -1){
            return dp[idx][sum1];
        }
        
        int ans1 = getAns(nums, n, tar, idx+1, sum1+nums[idx], sum2, dp);
        int ans2 = getAns(nums, n, tar, idx+1, sum1, sum2+nums[idx], dp);
        
        return dp[idx][sum1] = ans1 + ans2;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return getAns(nums, n, target, 0, 0, 0, dp);
    }
};
