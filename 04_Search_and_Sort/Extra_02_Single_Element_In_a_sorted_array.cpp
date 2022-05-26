class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); int ans = 0;
        if(n==1){
            return nums[0];
        }
        
        int lo = 0; int hi= n-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid]!=nums[(mid+1)%n] and nums[mid]!=nums[(mid+n-1)%n]){
                ans = nums[mid];
                break;
            }
            else if((nums[mid]==nums[(mid+1)%n] and mid%2==1) or (nums[mid]==nums[(mid-1+n)%n] and mid%2==0)){
                hi = mid-1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};
