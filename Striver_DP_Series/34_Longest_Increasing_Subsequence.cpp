// Recursive:

// Same concept of pick or not pick.

class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int idx, int last){
        if(idx >= n){
            return 0;
        }
        
        int ans = 0;
        
        if(nums[idx] > last){
            int ans1 = 1 + getAns(nums, n, idx+1, nums[idx]);
            int ans2 = getAns(nums, n, idx+1, last);
            ans = max(ans1, ans2);
        }
        
        else{
            ans = getAns(nums, n, idx+1, last);
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return getAns(nums, n, 0, -1e9);
    }
};



// Memoisation:


class Solution {
public:
    
    int getAns(vector<int>& nums, int n, int idx, int last, vector<vector<int>>& dp){
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx][last+1] != -1){
            return dp[idx][last+1];
        }
        
        int ans = 0;
        int ans1 = 0;
        
        if(last == -1 or nums[idx] > nums[last]){
            ans1 = 1 + getAns(nums, n, idx+1, idx, dp);
        }
        int ans2 = getAns(nums, n, idx+1, last, dp);
        
        ans = max(ans1, ans2);
        
        return  dp[idx][last+1] = ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};



// Tabulation: O(n2)

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        
        return ans;
    }
};



// Tabulation O(nlongn)


class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        
        for(int i=1; i<n; i++){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        
        return dp.size();
    }
};



