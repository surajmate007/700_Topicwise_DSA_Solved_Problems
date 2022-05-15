// first find nums[i] < nums[i+1] and mark i as index1. if idx1 == -1 then simply reverse that array.
// Then find nums[i] > nums[index1] then mark that i as index2.
// swap elements at index1 and index2 and then reverse the array after index1.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1; int idx2 = -1; int n = nums.size()-1;
        
        for(int i=n-1; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx1 = i;
                break;
            }
        }
        
        if(idx1 == -1){
            reverse(nums.begin() + idx1 + 1, nums.end());
            return;
        }
        
        for(int i=n; i>=0; i--){
            if(nums[i] > nums[idx1]){
                idx2 = i;
                break;
            }
        }
        
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin() + idx1 + 1, nums.end());
 
        return;
    }
};
