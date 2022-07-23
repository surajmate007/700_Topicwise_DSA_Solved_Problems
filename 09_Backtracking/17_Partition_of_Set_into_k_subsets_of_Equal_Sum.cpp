// More intuitive solution.
// Revise very very frequently.
// Good and intuitive solution:

class Solution {
public:
    
    bool getAns(vector<int>& nums, int n, int k, int csum, int osum, int idx, vector<int>& used){
        if(k==1){
            return true;
        }
        
        if(idx >= n){
            return false;
        }
        
        if(csum == osum){
            return getAns(nums, n, k-1, 0, osum, 0, used);
        }
        
        for(int i=idx; i<n; i++){
            if(used[i] == 0 and csum+nums[i] <= osum){
                used[i] = 1;
                if(getAns(nums, n, k, csum+nums[i], osum, i+1, used) == true){
                    return true;
                }
                used[i] = 0;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n){
            return false;
        }
        
        if(k==1){
            return true;
        }
        
        int osum = accumulate(nums.begin(), nums.end(), 0);
        
        if(osum % k != 0){
            return false;
        }
        
        osum /= k;
        vector<int> used(n, 0);
        sort(nums.begin(), nums.end(), greater<int>());
        return getAns(nums, n, k, 0, osum, 0, used);
    }
};


