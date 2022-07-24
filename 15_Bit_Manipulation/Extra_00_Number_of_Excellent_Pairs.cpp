// lEETCODE 303 CONTEST:
// Property : The sum of set bits in 2 number is equal to the sum of set bits in their bitwise OR and bitwise AND between these numbers.

class Solution {
public:
    
    int getSetBits(int n){
        int ans = 0;
        while(n > 0){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        vector<int> vec;
        vec.push_back(getSetBits(nums[0]));
        int len = 1;
        
        if(vec[0] * 2 >= k){
            ans = 1;
        }
        
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                len++;
                vec.push_back(getSetBits(nums[i]));
                if(vec.back() * 2 >= k){
                    ans++;
                }
            }
        }
        
        sort(vec.begin(), vec.end());
        
        int i=0; int j=len-1;
        
        while(i <= j){
            if(vec[i] + vec[j] >= k){
                ans += 2 * (j-i);
                j--;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};
