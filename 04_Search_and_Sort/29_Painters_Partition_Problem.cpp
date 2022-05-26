// Exactly same as Book allocation problem.

class Solution{
  public:
  
    bool allocateWork(int arr[], int n, int w, long long mid){
        long long sum = 0; int cnt = 1;
        for(int i=0; i<n; i++){
            sum += (long long)arr[i];
            if(sum > mid){
                sum = (long long)arr[i];
                cnt++;
            }
            if(cnt > w or arr[i] > mid){
                return false;
            }
        }
        return true;
    }
    
    
    long long minTime(int arr[], int n, int k){
        long long lo = INT_MAX; long long hi = 0; long long fans = LLONG_MAX;
        
        for(int i=0; i<n; i++){
            lo = min(lo, (long long)arr[i]);
            hi += (long long)arr[i];
        }
        
        while(lo <= hi){
            long long mid = (lo + hi)/2;
            allocateWork(arr, n, k, mid);
            if(allocateWork(arr, n, k, mid)){
                fans = min(fans, mid);
                hi = mid - 1;
            }
            else{
                lo = mid+1;
            }
        }
        return fans;
    }
};
