// Such type of problems can be easily solved using the sorting technique that we learned earlier.

int kthElement(int arr1[], int arr2[], int n, int m, int p){
        int i=0; int j=0; int k = n-1;
        while(i<=k and j<m){
            if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                swap(arr1[k], arr2[j]);
                k--; j++;
            }
        }
        sort(arr1, arr1+n);
        sort(arr2, arr2+m);
        if(p <= n){
            return arr1[p-1];
        }
        else{
            return arr2[p-n-1];
        }
}



// Program to find kth element from two sorted arrays

// Time Complexity: O(n) 
// Auxiliary Space : O(m + n)


#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k)
{
	int sorted1[m + n];
	int i = 0, j = 0, d = 0;
	while (i < m && j < n)
	{
		if (arr1[i] < arr2[j])
			sorted1[d++] = arr1[i++];
		else
			sorted1[d++] = arr2[j++];
	}
	while (i < m)
		sorted1[d++] = arr1[i++];
	while (j < n)
		sorted1[d++] = arr2[j++];
	return sorted1[k - 1];
}


// Time Complexity: O(k) 
// Auxiliary Space: O(1)

int find(int A[], int B[], int m,
         int n, int k_req)
{
    int k = 0, i = 0, j = 0;
 
    // Keep taking smaller of the current
    // elements of two sorted arrays and
    // keep incrementing k
    while(i < m && j < n)
    {
        if(A[i] < B[j])
        {
            k++;
            if(k == k_req)
                return A[i];
            i++;
        }
        else
        {
            k++;
            if(k == k_req)
                return B[j];
            j++;
        }
    }
 
    // If array B[] is completely traversed
    while(i < m)
    {
        k++;
        if(k == k_req)
            return A[i];
        i++;
    }
 
    // If array A[] is completely traversed
    while(j < n)
    {
        k++;
        if(k == k_req)
            return B[j];
        j++;
    }
}





// C++ program to find the kth element
// Best approach out of all the approaches.


#include <bits/stdc++.h>
using namespace std;
 
long long int maxN
    = 1e10; // the maximum value in the array possible.
 
long long int kthElement(int arr1[], int arr2[], int n,
                         int m, int k)
{
    long long int left = 1,
                  right
                  = maxN; // The range of where ans can lie.
    long long int ans = 1e15; // We have to find min of all
                              // the ans so take .
 
    // using binary search to check all possible values of
    // kth element
    while (left <= right) {
        long long int mid = (left + right) / 2;
        long long int up_cnt
            = upper_bound(arr1, arr1 + n, mid) - arr1;
        up_cnt += upper_bound(arr2, arr2 + m, mid) - arr2;
 
        if (up_cnt >= k) {
            ans = min(ans,
                      mid); // find the min of all answers.
            right
                = mid - 1; // Try to find a smaller answer.
        }
        else
            left = mid + 1; // Current mid is too small so
                            // shift right.
    }
 
    return ans;
}
 
