// easiest sliding window solution:
int smallestSubWithSum(int arr[], int n, int x){
    int sum = 0; int i=0; int j=0; int ans = INT_MAX; 
    while(j < n){
        sum += arr[j];
        j++;
        while(sum > x){
            ans = min(ans, j-i);
            sum -= arr[i];
            i++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}


// using sliding window technique where the window is present in between i and j

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];

        int large, small;
        for(int i=1; i<n; i++){
            if(arr[i]-k < 0){
                continue;
            }
            // here we are just checking whether any other element can be larger than large
            // or smaller than small.
            small = min(arr[0]+k, arr[i]-k);
            large = max(arr[n-1]-k, arr[i-1]+k);
            
            ans = min(ans, large - small);
        }
        
        return ans;
    }
};


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0, sum=0;                                // *Intializing variables*
        int ans = INT_MAX;
        while(j<nums.size() and i<=j){
            while(sum < target and j<nums.size()){
                sum += nums[j];
                j++;
            }
            while(sum >= target and i<j){
                ans = min(ans, j-i);
                sum -= nums[i];
                i++;
            }
        }
        if(ans==INT_MAX ? 0 : ans;}
        return ans;
    }
};
