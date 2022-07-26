// First applied binary search for the value in the matrix. then for every mid value we are counting the number of elements lesset than the mid using 
// upper bound.
// If the count of elements is more than k then we have to do hi = mid - 1 else lo = mid + 1.


class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];
        
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            int cnt = 0;
            for(int i=0; i<n; i++){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(cnt < k){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        
        return lo;
    }
};
