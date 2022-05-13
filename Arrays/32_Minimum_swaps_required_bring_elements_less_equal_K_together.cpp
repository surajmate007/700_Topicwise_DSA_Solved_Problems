// we wll first count total number of elements less than or equal to k in the given array.
// we will use sliding window technique where we will keep track of bad values (values greater than k) inside the window.
// then based on the number leaving the window and the number entering the window we will update the bad value.


int minSwap(int arr[], int n, int k) {
        int bv = 0; int ans = INT_MAX; int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                count++;
            }
        }
        int i=0; int j=count-1;
        for(int p=0; p<j+1; p++){
            if(arr[p] > k){
                bv++;
            }
        }
        ans = min(ans, bv);
        while(j < n){
            if(arr[i] > k){
                bv--;
            }
            if(arr[j] > k){
                bv++;
            }
            i++; j++;
            ans = min(ans, bv);
        }
        return ans;
}
