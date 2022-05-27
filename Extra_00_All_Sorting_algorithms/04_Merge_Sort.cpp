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
