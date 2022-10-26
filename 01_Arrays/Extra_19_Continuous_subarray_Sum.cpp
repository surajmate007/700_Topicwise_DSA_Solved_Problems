// Basically you want to create an array of the accumulated sum, but instead of the sum, you have the sum%k. If you just go through it normally
// and return on sum%k == 0, then that only accounts for (n) possibilities out of (n^2) possibilities. However, if you find duplicated sum%k values,
// then that the sub array between those two indexes will actually be the solution.

// i.e.
// [4, 1, 2, 3] and 6

// if we get the accumulated sum, it looks like this [4, 5, 7, 10]
// if we make it accumulated sum % k, it looks like this [4, 5, 1, 4]
// notice that there is duplicated 4's. The diffference between these two sums in theory must be a multiple of 6 since we've only been storing the num%k.
// Just wanted to write this out cz I thought it was pretty awesome and really couldn't figure it out for a while.




class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<long long, int> mp;
        mp[0] = 0;
        long long sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int val = sum%k;
            if(mp.find(val) != mp.end()){
                if(mp[val] < i){
                    return true;
                }
            }
            else{
                mp[val] = i+1;
            } 
        }

        return false;
    }
};
