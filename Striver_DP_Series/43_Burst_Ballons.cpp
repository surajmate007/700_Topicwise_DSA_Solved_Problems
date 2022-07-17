// Recursive Code:


class Solution {
public:
    
    int getAns(vector<int>& nums, int lo, int hi){
        if(lo == hi){
            return nums[lo-1]*nums[lo]*nums[lo+1];
        }
        
        int ans = 0;
        
        for(int k=lo; k<=hi; k++){
            int temp = getAns(nums, lo, k-1) + getAns(nums, k+1, hi) + nums[lo-1] * nums[k] * nums[hi+1];
            ans = max(ans, temp);
        }
        
        return ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        return getAns(nums, 1, n-2);
    }
};



// Memoisation:


class Solution {
public:
    
    int getAns(vector<int>& nums, int lo, int hi, vector<vector<int>>& dp){
        if(lo == hi){
            return nums[lo-1]*nums[lo]*nums[lo+1];
        }
        
        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
        
        int ans = 0;
        
        for(int k=lo; k<=hi; k++){
            int temp = getAns(nums, lo, k-1, dp) + getAns(nums, k+1, hi, dp) + nums[lo-1] * nums[k] * nums[hi+1];
            ans = max(ans, temp);
        }
        
        return dp[lo][hi] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        
        return getAns(nums, 1, n-2, dp);
    }
};
