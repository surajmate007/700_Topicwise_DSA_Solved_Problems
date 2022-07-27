class Solution {
public:
    
    int upper_bound(vector<int> nums, int target){
        int lo = 0; int hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] > target){
                hi = mid - 1; 
            }
            else{
                lo = mid + 1;
            }
        }
        
        return lo-1;
    }
    
    int lower_bound(vector<int> nums, int target){
        int lo = 0; int hi = nums.size()-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(nums[mid] < target){
                lo = mid + 1; 
            }
            else{
                hi = mid - 1;
            }
        }
        
        return hi+1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        int last = upper_bound(nums, target);
        
        if(first > last){
            return {-1, -1};
        }
        
        return {first, last};
    }
};
