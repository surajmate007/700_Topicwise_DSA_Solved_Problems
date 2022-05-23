// problem link : https://leetcode.com/problems/combination-sum/ 

class Solution {
public:
    void givesum(vector<int> nums, int idx, int n, vector<vector<int>>& ans, vector<int>& ds, int target){
        if(idx == n){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            givesum(nums, idx, n, ans, ds, target - nums[idx]);
            ds.pop_back();
        }
        givesum(nums, idx+1, n, ans, ds, target);
    }
        
                 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        givesum(candidates, 0, n, ans, ds, target);
        
        return ans;
    }
};
