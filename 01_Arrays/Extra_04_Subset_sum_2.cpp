class Solution {
public:
    void function(vector<int>& nums, set<vector<int>>& st, vector<int>& ds, int n, int idx){
        if(idx == n){
            st.insert(ds);
            return;
        }
        
        ds.push_back(nums[idx]);
        function(nums, st, ds, n, idx+1);
        ds.pop_back();
        function(nums, st, ds, n, idx+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int>ds;
        int n = nums.size();
        function(nums, st, ds, n, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
};

