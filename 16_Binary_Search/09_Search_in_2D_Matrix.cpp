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
