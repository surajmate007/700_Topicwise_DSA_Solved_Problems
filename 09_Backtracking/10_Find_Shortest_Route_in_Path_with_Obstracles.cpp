// brute force approach.
// Try all possible ways to reach the bottom right corner and then find the minimum steps to reach there.


class Solution {
public:
    
    void getAns(vector<vector<int>> grid, int n, int m, int i, int j, int k, int ds, int& ans){
        
        if(i==n-1 and j==m-1){
            ans = min(ans, ds);
            return;
        }
        
        if(k==-1){
            return;
        }
        
        int flag = grid[i][j];
        grid[i][j] = -1;
        
        if(i>0){
            if(grid[i-1][j] == 1 or grid[i-1][j] == 0){
                getAns(grid, n, m, i-1, j, k-grid[i-1][j], ds+1, ans);
            }
        }
        
        if(i<n-1){
            if(grid[i+1][j] == 1 or grid[i+1][j] == 0){
                getAns(grid, n, m, i+1, j, k-grid[i+1][j], ds+1, ans);
            }
        }
        
        if(j>0){
            if(grid[i][j-1] == 1 or grid[i][j-1] == 0){
                getAns(grid, n, m, i, j-1, k-grid[i][j-1], ds+1, ans);
            }
        }
        
        if(j<m-1){
            if(grid[i][j+1] == 1 or grid[i][j+1] == 0){
                getAns(grid, n, m, i, j+1, k-grid[i][j+1], ds+1, ans);
            }
        }
        
        grid[i][j] = flag;
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int ans = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        
        getAns(grid, n, m, 0, 0, k, 0, ans);
        
        if(ans == INT_MAX){
            return -1;
        }
        
        return ans;
    }
};





// Optimised : DFS:

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // top left down right
        vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1)));

        // for bfs, using queue
        queue<vector<int>> q;
        q.push({0, 0, k});
        
         // we are visiting it so marking as 1
        visited[0][0][k] = true;
        
        // will store the number of steps needed to reach the destination
        int countSteps = 0;
        
        // iterating over the queue
        while(!q.empty()){
            
            int size = q.size();
            
            // iterating level by level
            for(int i = 0; i < size; i++){
                auto curArr = q.front();
                q.pop();
                
                // if we reached the destination
                if(curArr[0] == m-1 && curArr[1] == n-1) {
                    return countSteps;
                }
                
                // exploring all the possible directions
                for(auto dir : directions){
                    int newRow = dir[0] + curArr[0];
                    int newCol = dir[1] + curArr[1];
                    int obstacle = curArr[2];
                    
                    // checking the boundary/base conditions
                    if(newRow >= 0 && newCol >= 0 && newRow < m && newCol < n){
                        
                        // if there is not obstacle and that place is not visited
                        if(grid[newRow][newCol] == 0 && !visited[newRow][newCol][obstacle]){
                            q.push({newRow, newCol, obstacle});
                            visited[newRow][newCol][obstacle] = true;
                        }
                        
                        // if there is obstable
                        // then checking if obstableBalance(k) is more than 0, then only we can break that obstacle and also checking whether that place is visited or not
                        if(grid[newRow][newCol] == 1 && obstacle > 0 && !visited[newRow][newCol][obstacle-1]){
                            q.push({newRow, newCol, obstacle-1});
                            visited[newRow][newCol][obstacle-1] = true;
                        }
                    }
                }
            }
            
            // after every level increase the countSteps by 1
            countSteps++;
        }
        
        // if unable to reach destination so return -1
        return -1;
    }
};
