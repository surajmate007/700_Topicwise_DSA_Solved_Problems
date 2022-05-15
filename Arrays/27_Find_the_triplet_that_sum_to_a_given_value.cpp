// Since expected TC is O(N2), hence we can sort the array which is less than N2 and then we will subtract one value from X and
// using 2 pointer method on sorted array we will try to find the 2 elements which satisfy the remaining sum.


bool find3Numbers(int arr[], int n, int X){
        sort(arr, arr+n);
        for(int i=0; i<n; i++){
            int dif = X-arr[i];
            int lo = i+1; int hi = n-1;
            while(lo < hi){
                if(dif == (arr[lo]+arr[hi])){
                    return true;
                }
                else if(dif < (arr[lo]+arr[hi])){
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        return false;
    }
