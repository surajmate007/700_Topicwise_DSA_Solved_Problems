// using dfs:

int dir1[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dir2[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int getAns(int** arr, int n, int m, int i, int j){
    arr[i][j] = 0;
    
    for(int d=0; d<8; d++){
        int x = i+dir1[d]; int y = j+dir2[d];
        if(x>=0 and y>=0 and x<n and y<m and arr[x][y]==1){
            getAns(arr, n, m, x, y);
        }
    }
    
    return 1;
}

int getTotalIslands(int** arr, int n, int m){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                ans += getAns(arr, n, m, i, j);
            }
        }
    }
    
    return ans;
}




// This is the brute force solution for this problem but giving TLE.
// I am using the concept of BFS.

class Solution {
  public:
    
    bool isValid(int x, int y, int n, int m, vector<vector<char>> a, vector<vector<int>> vis){
        if(x<n and y<m and x>=0 and y>=0 and a[x][y]=='1' and vis[x][y]==0){
            return true;
        }
        return false;
    }
    
    int numIslands(vector<vector<char>>& a) {
        int n = a.size(); int m = a[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
        queue<pair<int, int>> q;
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == '1' and vis[i][j] == 0){
                    q.push({i, j}); vis[i][j] = 1;
                  
                    while(!q.empty()){
                        auto e = q.front(); q.pop();
                        int x1 = e.first; int y1 = e.second;
                        for(auto d : dir){
                            int x = d[0]; int y = d[1];
                            if(isValid(x1+x, y1+y, n, m, a, vis)){
                                vis[x1+x][y1+y] = 1;
                                q.push({x1+x, y1+y});
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        
        return ans;
    }
};





// This is the code library code and also giving TLE:

class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int i, int j, int vis[][501], vector<vector<char>> A, int N, int M){
        if(i<0 or j<0 or i>=N or j>=M) return;
        if(A[i][j]=='0') return;
        
        if(!vis[i][j]){
            vis[i][j]=1;
            dfs(i+1,j,vis,A,N,M);
            dfs(i-1,j,vis,A,N,M);
            dfs(i,j+1,vis,A,N,M);
            dfs(i,j-1,vis,A,N,M);
            dfs(i+1,j+1,vis,A,N,M);
            dfs(i-1,j-1,vis,A,N,M);
            dfs(i+1,j-1,vis,A,N,M);
            dfs(i-1,j+1,vis,A,N,M);
        }
    }

    int numIslands(vector<vector<char>> A) {
        int N = A.size(); int M = A[0].size();
        
        // Your code here
        int vis[501][501];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                vis[i][j]=0;
            }
        }
        int c=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!vis[i][j] and A[i][j]=='1') {
                    dfs(i,j,vis,A,N,M);
                    c++;
                }
            }
        }
        return c;
    }
};
