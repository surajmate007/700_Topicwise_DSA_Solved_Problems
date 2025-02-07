// After every iteration we select the smallest element so far and put it at the front of the array.
// TC = O(n2)
// SC = O(1)

// It performs well on small length arrays.

#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if(minIdx != i){
            swap(arr[i], arr[minIdx]);
        }
    }
}

int main(){
    int arr[] = {7, 3, 4, 9, 23, 45, 11, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
