long long maxSubarraySum(int arr[], int n){
        long long csum = arr[0]; long long osum = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] <= (osum + arr[i])){
                osum += arr[i];
            }
            else{
                osum = arr[i];
            }
            
            if(csum < osum){
                csum = osum;
            }
        }
        return csum;
    }
