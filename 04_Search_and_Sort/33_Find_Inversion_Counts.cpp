// O(n2) complexity using simple two loops 

long long int inversionCount(long long arr[], long long N){ // main function
        long long inv = 0;
        for(int i=0; i<N; i++){
          for(int j=i+1; j<N; j++){
            if(arr[i] > arr[j]){
              inv++;
            }
          }
        }
  return inv;
}

// using merge sort appreoach. O(nlog(n)) complexity.

long long merge(long long arr[], long long temp[], int left, int mid, int right){. // function to merge two sorted arrays and also count the inversions
        int i,j,k = 0;
        long long inv = 0;
        i=left; j=mid; k=left;
        while((i<=mid-1) and (j<=right)){
            if(arr[i] <= arr[j]){
                temp[k] = arr[i]; k++; i++;
            }
            else{
                temp[k] = arr[j]; k++; j++; inv += (mid-i);
            }
        }
        while(i <= mid-1){
            temp[k] = arr[i];
            k++; i++;
        }
        while(j <= right){
            temp[k] = arr[j];
            k++; j++;
        }
        for(int m=left; m<=right; m++){
            arr[m] = temp[m];
        }
        return inv;
    }
    
    long long mergesort(long long arr[], long long temp[], int left, int right){  // function to split the arrays recursively
        long long inv = 0;
        if(left < right){
            int mid = (left + right)/2;
            inv += mergesort(arr, temp, left, mid);
            inv += mergesort(arr, temp, mid+1, right);
            inv += merge(arr, temp, left, mid+1, right);
        }
        return inv;
    }

    long long int inversionCount(long long arr[], long long N){                  // main function
        long long temp [N];
        return mergesort(arr, temp, 0, N-1);
    }



// Modification of inversion count : 
// here we need to return the array of smaller element son the right of the element. 

class Solution{
public:
    
    void merge(vector<int> &count,vector<pair<int,int>> &v,int left ,int mid,int right){
        
        vector<pair<int,int>> temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += right-j+1;
                temp[k++]=v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++]=v[i++]; 
        }
        while(j<=right){
            temp[k++]=v[j++];
        }
        for(int i=left;i<=right;i++){
            v[i]=temp[i-left];
        }
    }
    
    void mergeSort(vector<int> &count,vector<pair<int,int>> &v,int left,int right){
        
        if(left<right){
            int mid=left + (right-left)/2;
            mergeSort(count,v,left,mid);
            mergeSort(count,v,mid+1,right);
            merge(count,v,left,mid,right);
        }
    }


	vector<int> constructLowerArray(int *arr, int n) {
	    
	    vector<pair<int,int>>v(n);
	    
	    for(int i=0;i<n;i++){
	        pair<int,int>p;
	        p.first=arr[i];
	        p.second=i;
	        v[i]=p;
	    }
	    
	    vector<int>count(n,0);
	    
	    mergeSort(count,v,0,n-1);
	    
	    return count;
	    
	}
};
