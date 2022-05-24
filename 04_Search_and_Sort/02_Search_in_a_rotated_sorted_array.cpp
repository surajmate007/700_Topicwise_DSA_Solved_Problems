// Brute force taking O(n) time:
// using linear search 

int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
}

// Optomised approach using binary serach.
// In this approach we are usignthe fact at any time any one side of the array will be always sorted.
// ie either mid+1 to hi will be sorted or mid-1 to lo will be sorted.
// we are going to use this propterty only.
// We will the figure out which side is sorted and then check do our element lie in this sorted range.
// if element lies in this ramge then we will use simple binary serach approach in this range.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0; int hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi)>>1;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] >= nums[lo]){
                if(target>=nums[lo] and target <= nums[mid]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(target<=nums[hi] and target >= nums[mid]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        
        return -1;
    }
};
