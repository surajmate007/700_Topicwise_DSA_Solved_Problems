// This is the simple solution based on binary search approach.
// Keep in mind the low pointer will always give the proper position of the element if it is not present in the array.

class Solution{
    public:
    int searchInsertK(vector<int>arr, int N, int k){
        int lo = 0; int hi = N-1;
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid] == k){
                return mid;
            }
            
            else if(arr[mid] < k){
                lo = mid + 1;
            }
            
            else{
                hi = mid - 1;
            }
        }
        
        return lo;
    }
};
