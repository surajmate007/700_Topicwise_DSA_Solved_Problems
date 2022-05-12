// keeping one pointer at start of first array, second pointer at start of 2nd array and 3rd pointer at end of first array.
// compare elements at index i and j and then swap elemnts at index j and k.

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
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
	}
};
