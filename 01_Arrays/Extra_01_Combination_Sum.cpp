// problem link : https://leetcode.com/problems/combination-sum/ 
// Both the solutions follow same approach. But the first one is more intuitive.
class Solution {
public:
    vector<vector<int>> ans;
    void getAns(vector<int>& vec, vector<int>& temp, int idx, int n, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(idx >= n){
            return;
        }
        
        if(vec[idx] <= target){
            temp.push_back(vec[idx]);
            getAns(vec, temp, idx, n, target-vec[idx]);
            temp.pop_back();
        }
        getAns(vec, temp, idx+1, n, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> temp;
        getAns(candidates, temp, 0, n, target);
        return ans;
    }
};



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
