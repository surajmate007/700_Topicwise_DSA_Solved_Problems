// This problem can be solved using binary search approach.
// The speciality about binary search is if we know the search space where the answer is lying then we can implement binary search to find the answer.
// In book allocation problem we already know the limits within which the answer is lying ie the minimum pages can be the minimum of all pages in the 
// given array and the maximum pages can be the sum of all the book pages.
// Hence we properly know the search space for the answer.
// Now we have to figure out the conditions for which we should change the limits of this search space.
// Here after finding the mid we will see can we allocate pages such that the maximum pages will lie within the mid value.
// If it is possible then we will store that as temp ans to take minimum of all such answers and do (hi = mid -1) to further reduce the max pages allocated.
// If it is not possible to allocate to all the students then we will return -1 and do (lo = mid+ 1) to increase the allocation limit.

class Solution {
    public:
    //Function to find minimum number of pages.
    bool allocatePages(int arr[], int n, int s, int mid){
        int sum = 0; int cnt = 1;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                 sum = arr[i];
                 cnt++;
            }
            if(cnt > s){
                return false;
            }
        }
        return true;
    }
    
    int findPages(int arr[], int N, int M) {
        int lo = INT_MAX; int hi = 0; int ans = 0;
        for(int i=0; i<N; i++){
             lo = min(lo, arr[i]);
             hi += arr[i];
        }
        
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            bool flag = allocatePages(arr, N, M, mid);
            if(flag == false){
                lo = mid+1;
            }
            else{
                ans = mid;
                hi = mid-1;
            }
        }
        return ans;
    }
};
