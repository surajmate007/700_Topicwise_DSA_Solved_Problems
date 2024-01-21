// similar approach like combination sum 2:

class Solution {
public:
    vector<vector<int>> ans;
    void getAns(vector<int>& nums, vector<int>& temp, int idx, int n){
        ans.push_back(temp);

        for(int i=idx; i<n; i++){
            if(i>idx and nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            getAns(nums, temp, i+1, n);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> temp;
        getAns(nums, temp, 0, n);

        return ans;
    }
};


// Brute approach using set.
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

