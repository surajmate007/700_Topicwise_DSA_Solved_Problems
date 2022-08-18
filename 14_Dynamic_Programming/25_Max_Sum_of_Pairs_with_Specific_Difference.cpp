// this is the simple solution where we are first sorting the array and then starting from the end of the array and keep on forming the pairs greedily.

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k){
        sort(arr, arr+n);
        int ans = 0;
        
        for(int i=n-1; i>0; i--){
            if(arr[i]-arr[i-1] < k){
                ans += (arr[i] + arr[i-1]);
                i--;
            }
        }
        
        return ans;
    }
};
