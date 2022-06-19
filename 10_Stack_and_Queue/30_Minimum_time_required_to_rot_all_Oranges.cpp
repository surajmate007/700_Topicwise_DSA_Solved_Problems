// This is the solutioon written by me. But not working.

class Solution{
  public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        long long cnt = 0; int ans = 0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 or grid[i][j] == 2){
                    cnt++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        if(cnt == m*n){
            return ans;
        }
        
        while(!q.empty()){
            int s = q.size();
            ans++;
            while(s--){
                auto& p = q.front();
                q.pop();
                
                for(auto d : dir){
                    int x = p.first + d.first; int y = p.second + d.second;
                    if(x>=0 and x<n and y>=0 and y<m and grid[x][y] == 1){
                        cout<<"Rotted : "<<x<<" "<<y<<endl;
                        q.push({x, y});
                        cnt++;
                        grid[x][y] = 2;
                    }
                }
            }
            
            if(cnt == m*n){
                break;
            }
        }
        
        cout<<cnt<<endl;
        
        if(cnt == m*n){
            return ans;
        }
        
        return -1;
    }
};



// Same solution approach:

bool isValid (int i, int j, int n, int m, vector<vector<int>>& grid){
        if (i>=0 && j>=0 && i<n && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), tot = 0;
        
        queue <pair<int,int> > q;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if(grid[i][j]!=0){
                    tot++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int count = 0, timer = 0;
        
        while (!q.empty()){
            int k = q.size();
            count += k;
            
            while (k--){
                int i = q.front().first, j = q.front().second;
                q.pop();
                
                if (isValid(i-1,j, n, m, grid)){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                
                if (isValid(i+1,j, n, m, grid)){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                
                if (isValid(i,j-1, n, m, grid)){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                
                if (isValid(i,j+1, n, m, grid)){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
            
            if (!q.empty()){
                timer++;
            }
        }
        
        return tot==count?timer:-1;
    }
