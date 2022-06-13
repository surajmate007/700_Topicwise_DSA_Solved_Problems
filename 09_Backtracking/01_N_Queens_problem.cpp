// This is the column wise approach for this problem:   GFG Solution
// It is easy problem


class Solution{
public:

    void fillGrid(vector<pair<int, int>> qpos, int n, vector<vector<int>>& grid){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = 0;
            }
        }
        
        for(auto e : qpos){
            int i = e.first; int j = e.second;
            
            for(int k=0; k<n; k++){
                grid[i][k] = 1;
                grid[k][j] = 1;
                if(i+k < n and j+k < n){
                    grid[i+k][j+k] = 1;
                }
                if(i-k>=0 and j-k>=0){
                    grid[i-k][j-k] = 1;
                }
                if(i+k<n and j-k>=0){
                    grid[i+k][j-k] = 1;
                }
                if(i-k>=0 and j+k<n){
                    grid[i-k][j+k] = 1;
                }
            }
        }
    }
    
    
    void getQueens(int n, int j, vector<int>& ds, vector<pair<int, int>>& qpos, vector<vector<int>>& ans, vector<vector<int>>& grid){
        
        if(j==n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(grid[i][j] == 0){
                qpos.push_back({i, j});
                fillGrid(qpos, n, grid);
                ds.push_back(i+1);
                
                getQueens(n, j+1, ds, qpos, ans, grid);
                
                qpos.pop_back();
                fillGrid(qpos, n, grid);
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> grid(n, vector<int> (n, 0));
        vector<int> ds;
        vector<pair<int, int>> qpos;
        vector<vector<int>> ans;
        getQueens(n, 0, ds, qpos, ans, grid);
        
        return ans;
    }
};



// Row-wise approach for this problem:  Leetcode Solution

class Solution {
public:
    
    void fillGrid(vector<vector<int>>& grid, vector<pair<int, int>> qpos, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                grid[i][j] = 0;
            }
        }
        
        for(auto e : qpos){
            int r = e.first; int c = e.second;
            for(int i=0; i<n; i++){
                grid[r][i] = 1;
                grid[i][c] = 1;
                if(r+i < n and c+i < n){
                    grid[r+i][c+i] = 1;
                }
                if(r-i >=0 and c-i >= 0){
                    grid[r-i][c-i] = 1;
                }
                if(r-i >=0 and c+i < n){
                    grid[r-i][c+i] = 1;
                }
                if(r+i < n and c-i >=0){
                    grid[r+i][c-i] = 1;
                }
            }
        }
    }
    
    string formStr(int n, int c){
        string str = "";
        for(int i=0; i<n; i++){
            if(i==c){
                str += 'Q';
            }
            else{
                str += '.';
            }
        }
        
        return str;
    }
    
    
    void nqueens(vector<vector<int>>& grid, vector<vector<string>>& ans, vector<string>& ds, vector<pair<int, int>>& qpos, int r, int n){
        if(r == n){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++){
            if(grid[r][i] != 1){
                qpos.push_back({r, i});
                fillGrid(grid, qpos, n);
                string str = formStr(n, i);
    
                ds.push_back(str);
                nqueens(grid, ans, ds, qpos, r+1, n);
                
                qpos.pop_back();
                ds.pop_back();
                fillGrid(grid, qpos, n);
                
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds;
        vector<pair<int, int>> qpos;
        vector<vector<int>> grid(n, vector<int> (n, 0));
        nqueens(grid, ans, ds, qpos, 0, n);
        return ans;
    }
};
