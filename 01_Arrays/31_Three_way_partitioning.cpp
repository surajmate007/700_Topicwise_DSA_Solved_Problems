// using 2 pointer and one iterator.

void threeWayPartition(int arr[], int n, int a, int b){
    int lo = 0; int hi = n-1;
    for(int i=0; i<n; i++){
        if(arr[i] < a){
            swap(arr[i], arr[lo]);
            lo++;
        }
        else if(arr[i] > b){
            swap(arr[i], arr[hi]);
            hi--; i--;
        }
    }
}

// using three pointers low, high and mid

void threeWayPartition(vector<int>& array, int a, int b){
    int low = 0, high = array.size() - 1, mid = 0;

    while (mid <= high) {
        if (array[mid] < a) {
            swap(array[mid++], array[low++]);   // we r sure after swap we won't get <a, bcoz it would have processed earlier.
        }
        else if (array[mid] > b) {
            swap(array[high--], array[mid]);    // here it is possible that after swap we can get >b value again hence no increment in mid.
        }
        else mid++;
    }
}
