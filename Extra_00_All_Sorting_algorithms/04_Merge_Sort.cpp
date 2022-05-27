// Auxiliary Space: O(n)
// Algorithmic Paradigm: Divide and Conquer
// Sorting In Place: No in a typical implementation
// Stable: Yes
// Time complexity of Merge Sort is  θ(nLogn) in all 3 cases (worst, average and best) as merge sort always divides the array
// into two halves and takes linear time to merge two halves.

// Drawbacks of Merge Sort

// Slower comparative to the other sort algorithms for smaller tasks.
// Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
// It goes through the whole process even if the array is sorted.




class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {  
        
        int size1 = m-l+1;
        int size2 = r-m;
        
        int leftArr[size1], rightArr[size2];
        
        for(int itr = 0; itr < size1; itr++){
            leftArr[itr] = arr[itr+l];
        }
        
        for(int itr = 0; itr < size2; itr++){
            rightArr[itr] = arr[itr+m+1];
        }
        
        int itr1 = 0, itr2 = 0, itr3 = l;
        
        while(itr1 < size1 && itr2 < size2){
            if(leftArr[itr1] <= rightArr[itr2]){
                arr[itr3++] = leftArr[itr1++]; 
            }else{
                arr[itr3++] = rightArr[itr2++];
            }
        }
        
        while(itr1 < size1){
            arr[itr3++] = leftArr[itr1++];
        }
        
        while(itr2 < size2){
            arr[itr3++] = rightArr[itr2++];
        }
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {   
        if(r > l){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1, r);
            merge(arr,l,mid,r);
        }
    }
};





// C++ program in-place Merge Sort
#include <iostream>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
// Inplace Implementation
void merge(int arr[], int start, int mid, int end)
{
	int start2 = mid + 1;

	// If the direct merge is already sorted
	if (arr[mid] <= arr[start2]) {
		return;
	}

	// Two pointers to maintain start
	// of both arrays to merge
	while (start <= mid && start2 <= end) {

		// If element 1 is in right place
		if (arr[start] <= arr[start2]) {
			start++;
		}
		else {
			int value = arr[start2];
			int index = start2;

			// Shift all the elements between element 1
			// element 2, right by 1.
			while (index != start) {
				arr[index] = arr[index - 1];
				index--;
			}
			arr[start] = value;

			// Update all the pointers
			start++;
			mid++;
			start2++;
		}
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {

		// Same as (l + r) / 2, but avoids overflow
		// for large l and r
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout <<" "<< A[i];
	cout <<"\n";
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, arr_size - 1);

	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by shivanisinghss2110


