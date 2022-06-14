// Repeated problem.
// Since backtracking solution has more complexity hence giving TLE.

class Solution{
public:
    
    bool isPossible(int a[], int idx, int n, int osum, int csum){
        if(idx == n){
            if(osum - csum == csum){
                return true;
            }
            return false;
        }
        
        if(isPossible(a, idx+1, n, osum, csum + a[idx])){
            return true;
        }
        
        if(isPossible(a, idx+1, n, osum, csum)){
            return true;
        }
    }
    
    int equalPartition(int n, int arr[]){
        int osum = 0;
        for(int i=0; i<n; i++){
            osum += arr[i];
        }
        return isPossible(arr, 0, n, osum, 0);
    }
};
