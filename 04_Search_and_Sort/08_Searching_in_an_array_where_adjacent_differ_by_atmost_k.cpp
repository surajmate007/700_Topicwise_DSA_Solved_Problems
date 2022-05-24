// This is the brute force approach for solving this problem

int search(int arr[], int n, int x, int k){
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}    
