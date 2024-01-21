// simply finding max and min element in each operation and finding the difference.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mn = nums[0]; int mx = nums[n-1];
        int ans = 0; int idx = n-2;

        while(mn != mx){
            int diff = (mx - mn);
            ans += diff;
            mn = mx;
            mx = nums[idx] + ans;
            idx--;
        }
        
        return ans;
    }
};
