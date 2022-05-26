// this is simple binary search approach :

int search(int arr[], int lo, int hi, int key){
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(arr[mid] == key){
                return mid;
            }
            else if(arr[mid] > arr[lo]){
                if(key < arr[mid] and key >= arr[lo]){
                    hi = mid-1;
                }
                else{
                    lo = mid + 1;
                }
            }
            else{
                if(key > arr[mid] and key <= arr[hi]){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
        
        return -1;
  }
