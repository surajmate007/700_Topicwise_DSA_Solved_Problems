class Solution {
public:
    void getsum(vector<int> nums, int idx, int n, vector<vector<int>>& ans, vector<int>& ds, int target){
        
        if(target == 0){
            ans.push_back(ds);
            return;
        }
            
        for(int i=idx; i<n; i++){
            if(i > idx and nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i] > target){
                break;
            }
            ds.push_back(nums[i]);
            getsum(nums, i+1, n, ans, ds, target-nums[i]);
            ds.pop_back();
        }
    } 
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        getsum(candidates, 0, n, ans, ds, target);
        return ans;
    }
};
