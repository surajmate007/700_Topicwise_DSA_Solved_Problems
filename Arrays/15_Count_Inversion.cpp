// O(n2) complexity using simple two loops 

long long int inversionCount(long long arr[], long long N){ // main function
        long long inv = 0;
        for(int i=0; i<N; i++){
          for(int j=i+1; j<N; j++){
            if(arr[i] > arr[j]){
              inv++;
            }
          }
        }
  return inv;
}


// using merge sort appreoach. O(nlog(n)) complexity.

long long merge(long long arr[], long long temp[], int left, int mid, int right){. // function to merge two sorted arrays and also count the inversions
        int i,j,k = 0;
        long long inv = 0;
        i=left; j=mid; k=left;
        while((i<=mid-1) and (j<=right)){
            if(arr[i] <= arr[j]){
                temp[k] = arr[i]; k++; i++;
            }
            else{
                temp[k] = arr[j]; k++; j++; inv += (mid-i);
            }
        }
        while(i <= mid-1){
            temp[k] = arr[i];
            k++; i++;
        }
        while(j <= right){
            temp[k] = arr[j];
            k++; j++;
        }
        for(int m=left; m<=right; m++){
            arr[m] = temp[m];
        }
        return inv;
    }
    
    long long mergesort(long long arr[], long long temp[], int left, int right){  // function to split the arrays recursively
        long long inv = 0;
        if(left < right){
            int mid = (left + right)/2;
            inv += mergesort(arr, temp, left, mid);
            inv += mergesort(arr, temp, mid+1, right);
            inv += merge(arr, temp, left, mid+1, right);
        }
        return inv;
    }

    long long int inversionCount(long long arr[], long long N){ // main function
        long long temp [N];
        return mergesort(arr, temp, 0, N-1);
    }
