class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        
        int ans;
        int lo =0; int hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(nums[mid] < nums[(mid+n-1)%n] and nums[mid] < nums[(mid+1)%n]){
                ans = nums[mid];
                break;
            }
            else if(nums[mid] < nums[hi]){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans; 
    }
};
