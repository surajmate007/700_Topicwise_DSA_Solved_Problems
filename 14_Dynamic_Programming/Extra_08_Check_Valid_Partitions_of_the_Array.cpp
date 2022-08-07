// very intuitive solution

class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int idx, vector<int>& dp){
        if(idx == n){
            return 1;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        int ans1 = 0; int ans2 = 0;
        
        if(idx+1<n){
            if(nums[idx] == nums[idx+1]){
                ans1 = getAns(nums, n, idx+2, dp);
            }
        }
        
        if(idx+2 < n){
            if((nums[idx] == nums[idx+1] and nums[idx] == nums[idx+2]) or nums[idx]+1 == nums[idx+1] and nums[idx+1]+1 == nums[idx+2]){
                ans2 = getAns(nums, n, idx+3, dp);
            }
        }
        
        return dp[idx] = ans1 or ans2;
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return getAns(nums, n, 0, dp);
    }
};
