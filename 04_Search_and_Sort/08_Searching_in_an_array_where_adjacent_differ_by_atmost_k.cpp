// This is the brute force approach for solving this problem

int search(int arr[], int n, int x, int k){
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}    



// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k){
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;

        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i] - x) / k);
    }

    cout << "number is not present!";
    return -1;
}
