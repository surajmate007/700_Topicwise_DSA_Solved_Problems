class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i=0;
       // This is cyclic sort algoritm which helps to put all the elements at their correct index.
        while(i<n){
            if(nums[i] > 0 and nums[i] <= n and nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        return n+1;
    }
};
