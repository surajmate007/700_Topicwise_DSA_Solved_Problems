// TC = O(n2)
// SC = O(1)

// when input is almost sorted
// space is a concern

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {7, 3, 4, 9, 23, 45, 11, 34};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
