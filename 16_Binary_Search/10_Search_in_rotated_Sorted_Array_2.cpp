class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0; int hi = n-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] == target){
                return true;
            }
            
            else if(nums[lo] == nums[mid] and nums[hi] == nums[mid]){
                lo++; hi--;
            }

            else if(nums[mid] >= nums[lo]){
                if(target >= nums[lo] and target < nums[mid]){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }  
            
            else{
                if(target <= nums[hi] and target > nums[mid]){
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1; 
                }
            }
        }
        
        return false;
    }
};
