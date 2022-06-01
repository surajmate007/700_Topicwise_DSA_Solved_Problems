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


int upper_bound(int arr[], int n, int val){
        int lo = 0; int hi = n-1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(arr[mid] > val){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        
        return lo;
    }
    
    int kthElement(int arr1[], int arr2[], int n, int m, int k){
       int lo = min(arr1[0], arr2[0]);
       int hi = max(arr1[n-1], arr2[m-1]); int ans = INT_MAX;
       
       while(lo <= hi){
           int cnt = 0;
           int mid = (lo + hi)/2;
           cnt += upper_bound(arr1, n, mid);
           cnt += upper_bound(arr2, m, mid);
           if(cnt >= k){
               ans = min(ans, mid);
               hi = mid-1;
           }
           else{
               lo = mid + 1;
           }
       }
       
       return ans;
    }
 
 
