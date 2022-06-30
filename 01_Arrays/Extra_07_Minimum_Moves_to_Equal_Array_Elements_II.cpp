// Leetcode Problem No : 462.


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int ans = 0; int n = nums.size();
        int med = 0;
        
        sort(nums.begin(), nums.end());
        
        if(n%2 == 1){
            med = nums[n/2];
        }
        else{
            med = (nums[n/2]+nums[n/2 - 1])/2;
        }
        
        
        for(int i=0; i<n; i++){
            if(nums[i] < med){
                ans += (med - nums[i]);
            }
            else{
                ans += (nums[i] - med);
            }
        }
        
        return ans;
    }
};
  
  
