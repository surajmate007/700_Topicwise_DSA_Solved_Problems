class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int ans = arr[n-1] - arr[0];
        int smallest = arr[0]+k; int largest = arr[n-1]-k;  // smallest and largest reepresent smallest and largest height possible in complete array
        int mi, ma;
        for(int i=0; i<n-1; i++){
            mi = min(smallest, arr[i+1]-k);
            ma = max(largest, arr[i]+k);
            if(mi < 0){
                continue;
            }
            ans = min(ans, ma-mi);
        }

        return ans;
    }    
};


// More intuitive way :

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
