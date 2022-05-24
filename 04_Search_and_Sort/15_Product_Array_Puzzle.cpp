// we are first finding the product of all the numbers excluding 0 and counting the number of 0s.
// if 0s are present in the array then the product at index of all non zero will be 0.
// If 1 0 is present then the product at indx of this 0 will be product of all non zeros.
// If multiple 0s are present then the product of all the entities will be 0.

// TC = O(n)

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> ans(n, 0);
        long long int pro = 1;
        int zcnt = 0;
        for(auto e : nums){
            if(e != 0){
                pro = pro * e;
            }
            else{
                zcnt++;
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] != 0 ){
                if(zcnt){
                    ans[i] = 0;
                }
                else{
                    ans[i] = pro / nums[i];
                }
            }
            else{
                if(zcnt > 1){
                    ans[i] = 0;
                }
                else{
                    ans[i] = pro;
                }
            }
        }
        
        return ans;
    }
};
