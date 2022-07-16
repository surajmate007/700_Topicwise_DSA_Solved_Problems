// Exactly same code as LIS only changes in condition.


class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n), ans;
        int maxi = 0; int last = 0;
        
        for(int i=1; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 and dp[i] < dp[j]+1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                last = i;
            }
        }
        
        ans.push_back(nums[last]);
        
        while(hash[last] != last){
            last = hash[last];
            ans.push_back(nums[last]);
        }
        
        return ans;
    }
};
