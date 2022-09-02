// sme different type of dp utilization. Here we are just seeing whether er already went over the same index and addition or not.

class Solution {
public:
    int dp[101][10001];
    
    void getAns(vector<int>& nums, int n, int idx, int sum, set<int>& st){
        if(idx >= n){
            st.insert(sum);
            return;
        }
        
        if(dp[idx][sum] == 1){
            return;
        }
        
        getAns(nums, n, idx+1, sum+nums[idx], st);
        getAns(nums, n, idx+1, sum, st);
        
        dp[idx][sum] = 1;
    }
    
	vector<int> DistinctSum(vector<int>nums){
	    int n = nums.size();
	    set<int> st;
	    vector<int> ans;
	    memset(dp, -1, sizeof(dp));
	    
	    getAns(nums, n, 0, 0, st);
	    for(auto e : st){
	        ans.push_back(e);
	    }
	    
	    return ans;
	}
};
