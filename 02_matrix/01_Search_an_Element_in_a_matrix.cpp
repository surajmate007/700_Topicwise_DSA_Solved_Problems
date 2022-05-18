// To search an element in matrix we will use the sorted property of an array to reduce the saerch complexity.
// we will first go through all the elements in last column to finalize the row for searching and then using binary saerch
// in that row due to its sorted nature.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1; int j = matrix[0].size()-1;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][j] >= target){
                row = i;
                break;
            }
        }
        
        if(row == -1){
            return false;
        }
        
        int start = 0; int end = j;
        while(start <= end){
            int mid = (start + end)/2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return false;
    }
};
