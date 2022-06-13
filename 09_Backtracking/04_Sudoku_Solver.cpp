// Easy solution:
// We are simply trying each entry in each cell hence the complexity is O(9^(N^2)).

class Solution{
  public:
    //Function to find a solved Sudoku.
    
    bool isPossible(int i, int j, int val, int a[N][N]){
        for(int k=0; k<N; k++){
            if(a[i][k] == val){
                return false;
            }
            if(a[k][j] == val){
                return false;
            }
            int p = (i/3)*3 + k%3; int q = (j/3)*3 + k%3;
            if(a[p][q] == val){
                return false;
            }
        }
        return true;
    }
    
    bool SolveSudoku(int a[N][N]){ 
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(a[i][j] == 0){
                    for(int k=1; k<=N; k++){
                        if(isPossible(i, j, k, a)){
                            a[i][j] = k;
                            if(SolveSudoku(a) == true){
                                return true;
                            }
                            else{
                                a[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
