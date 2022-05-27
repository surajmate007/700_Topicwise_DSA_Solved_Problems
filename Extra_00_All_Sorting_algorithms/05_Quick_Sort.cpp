// The solution of above recurrence is also O(nLogn)
// Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort
// and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures,
// and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case
// rarely occurs for a given type of data. However, merge sort is generally considered better when data is huge and stored in external storage. 
 

// Is QuickSort stable? 
// The default implementation is not stable. However any sorting algorithm can be made stable by considering indexes as comparison parameter. 

// Is QuickSort In-place? 
// As per the broad definition of in-place algorithm it qualifies as an in-place sorting algorithm as it uses extra space only for
// storing recursive function calls but not for manipulating the input. 

// Why MergeSort is preferred over QuickSort for Linked Lists? 
// In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays,
// linked list nodes may not be adjacent in memory. Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time.
// Therefore merge operation of merge sort can be implemented without extra space for linked lists.
// In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the address of A[0]
// be x then to access A[i], we can directly access the memory at (x + i*4). Unlike arrays, we can not do random access in linked list.
// Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to
// i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially
// and the need of random access is low. 



/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver Code
int main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// This code is contributed by rathbhupendra

