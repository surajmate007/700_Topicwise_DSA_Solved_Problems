// We have learned that when we use vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}} then it takes more time for execution.
// simple and fast way is using int dir[5] = {0, 1, 0, -1, 0}.

class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    
    
    int getAns(vector<vector<int>>& grid, int& n, int& m, int i, int j){

        int p = grid[i][j];
        grid[i][j] = 0;
        
        int temp = 0;
        for(int d=0; d<4; d++){
            int x = i+dir[d]; int y = j+dir[d+1];
            if(x>=0 and y>=0 and x<n and y<m and grid[x][y] != 0){
                temp = max(temp, grid[x][y] + getAns(grid, n, m, x, y));
            }
        }
        
        grid[i][j] = p;
        
        return temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] != 0){
                    ans = max(ans, grid[i][j] + getAns(grid, n, m, i, j));
                }
            }
        }
        
        return ans;
    }
};
