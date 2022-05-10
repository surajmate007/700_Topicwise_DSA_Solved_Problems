void rotate(int arr[], int n){
    int last = arr[n-1];
    for(int i=0; i<n; i++){
        int ele = arr[i];
        arr[i] = last;
        last = ele;
    }
}

