// using sliding window techmnique where the window is present in between i and j

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum=0; // *Intializing variables*
        int ans = INT_MAX;
        while(j<nums.size() and i<=j){
            while(sum < target and j<nums.size()){
                sum += nums[j];
                j++;
            }
            while(sum >= target and i<j){
                ans = min(ans, j-i);
                sum -= nums[i];
                i++;
            }
        }
        if(ans==INT_MAX)return 0;
        else return ans;
    }
};
