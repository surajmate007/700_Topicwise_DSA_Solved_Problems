// This is the simple solution where the heaps are given in array format and then we are merging the arrays and applying heapifi on them.

class Solution{
    public:
    void heapify(vector<int>& arr, int n, int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l < n and arr[l] > arr[i]){
            largest = l;
        }
        
        if(r < n and arr[r] > arr[largest]){
            largest = r;
        }
        
        if(i != largest){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(a[i]);
        }
        for(int i=0; i<m; i++){
            ans.push_back(b[i]);
        }
        
        n = n+m;
        for(int i=(n/2)-1; i>=0; i--){
            heapify(ans, n, i);
        }
        
        return ans;
    }
};
