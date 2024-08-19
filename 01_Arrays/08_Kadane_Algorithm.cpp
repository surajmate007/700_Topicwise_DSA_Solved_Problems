// simple solution -> osum cant be negative and csum is the max value osum can reach.
class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        int n = nums.size();
        int csum = INT_MIN; int osum = 0;
        for(int i=0; i<n; i++){
            osum = max(osum, 0);
            osum += nums[i];
            csum = max(csum, osum);
        }
        return csum;
    }
};


long long maxSubarraySum(int arr[], int n){
        long long csum = arr[0]; long long osum = arr[0];
        for(int i=1; i<n; i++){
            if(osum < 0){
                osum = 0;
            }
            osum += arr[i];
            if(csum < osum){
                csum = osum;
            }
        }
        return csum;
}
