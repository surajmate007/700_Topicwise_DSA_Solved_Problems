// This is binary search approach for this problem

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1; int high = nums.size()-1; int cnt;
        while(low <= high){
            int mid = low + (high-low)/2;
            cnt = 0;
            for(int n : nums){
                if(n <= mid){
                    cnt++;
                }
            }
            if(cnt <= mid){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};

// This is slow pointer fast pointer approach for this problem.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0]; int fast = nums[0];
        do{
            slow = nums[slow]; fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow]; fast = nums[fast];
        }
        return slow;
    }
};
