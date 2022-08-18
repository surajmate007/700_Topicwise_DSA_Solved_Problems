// we can simply use the prefix sum but it will take O(n2) time hence not efficient.


// arr[] = [1, 2, 3], n = 3
// All subarrays :  [1], [1, 2], [1, 2, 3], 
//                  [2], [2, 3], [3]
// here first element 'arr[0]' appears 3 times    
//      second element 'arr[1]' appears 4 times  
//      third element 'arr[2]' appears 3 times

// Every element arr[i] appears in two types of subsets:
// i)  In subarrays beginning with arr[i]. There are 
//     (n-i) such subsets. For example [2] appears
//     in [2] and [2, 3].
// ii) In (n-i)*i subarrays where this element is not
//     first element. For example [2] appears in 
//     [1, 2] and [1, 2, 3].

// Total of above (i) and (ii) = (n-i) + (n-i)*i 
//                             = (n-i)(i+1)
                                  
// For arr[] = {1, 2, 3}, sum of subarrays is:
//   arr[0] * ( 0 + 1 ) * ( 3 - 0 ) + 
//   arr[1] * ( 1 + 1 ) * ( 3 - 1 ) +
//   arr[2] * ( 2 + 1 ) * ( 3 - 2 ) 

// = 1*3 + 2*4 + 3*3 
// = 20

// This approach has O(n) time complexity.

// Efficient C++ program to compute sum of
// subarray elements
#include<bits/stdc++.h>
using namespace std;

//function compute sum all sub-array
long int SubArraySum( int arr[] , int n )
{
	long int result = 0;

	// computing sum of subarray using formula
	for (int i=0; i<n; i++)
		result += (arr[i] * (i+1) * (n-i));

	// return all subarray sum
	return result ;
}

// driver program to test above function
int main()
{
	int arr[] = {1, 2, 3} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Sum of SubArray : "
		<< SubArraySum(arr, n) << endl;
	return 0;
}

