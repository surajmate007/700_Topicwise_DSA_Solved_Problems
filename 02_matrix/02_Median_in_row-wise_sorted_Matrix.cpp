// Brute Force Approach: 

// we will store all the matrix elements in a vector or array and then sort that vector and then find the middle element in that vector 
// to get the median.

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
        vector<int> vec;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                vec.push_back(matrix[i][j]);
            }
        }
        sort(vec.begin(), vec.end());
        int mid = vec.size()/2;
        return vec[mid];
    }
};

// this is more intelligent approach using bianry search property.
// IN this we will first find the mid and then count all the elements less than this mid. If the count of elements are less than or equal to mid then
// we will shift mid to right (mid++) else we wil shift mid to left.
// the low index found at the end will be the required index of the median.

class Solution{   
public:
    int upperbound(vector<int>& arr, int val, int c){
        int lo = 0; int hi = c-1;
        while(lo <= hi){
            int mid = (lo+hi) >> 1;
            if(arr[mid] <= val){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
    }
    
    int median(vector<vector<int>> &matrix, int r, int c){
        int low = 1; int high = 1e9;
        while(low <= high){
            int mid = (low+high)>> 1;
            int cnt = 0;
            for(int i=0; i<r; i++){
                cnt += upperbound(matrix[i], mid, c);
            }
            
            if(cnt <= (r*c)/2){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        
        return low;
    }
};
