// Recursive:


class Solution {
public:
    bool getAns(vector<int>& nums, int tar, int idx){
        if(tar < 0){
            return false;
        }
        
        if(idx == nums.size()){
            if(tar == 0){
                return true;
            }
            return false;
        }
        
        bool ans = getAns(nums, tar-nums[idx], idx+1) or getAns(nums, tar, idx+1);
        
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        return getAns(nums, sum/2, 0);
    }
};



// Memoised:


class Solution {
public:
    bool getAns(vector<int>& nums, int tar, int idx, vector<vector<int>>& dp){
        if(tar < 0){
            return false;
        }
        
        if(idx == nums.size()){
            if(tar == 0){
                return true;
            }
            return false;
        }
        
        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }
        
        bool ans = getAns(nums, tar-nums[idx], idx+1, dp) or getAns(nums, tar, idx+1, dp);
        
        return dp[idx][tar] = ans;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        
        int tar = sum/2;
        int n = nums.size();
        
        vector<vector<int>> dp(n+1, vector<int>(tar+1, -1));
        
        return getAns(nums, sum/2, 0, dp);
    }
};





// Tabulation

class Solution {
  public:
    bool subsetSum(vector<int>& nums, int sum){
        bool dp[nums.size()+1][sum+1];
        for(int i=0; i<=nums.size(); i++){
            dp[i][0] = true;
        }
        for(int j=0; j<=sum; j++){
            dp[0][j] = false;
        }
        for(int i=1; i<=nums.size(); i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = (dp[i-1][j-nums[i-1]] or dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        else{
            return subsetSum(nums, sum/2);
        }
    }
};
