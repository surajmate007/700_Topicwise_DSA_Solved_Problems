// simple bfs based approach:

class Solution {
public:
    int dir[5] = {0, 1, 0, -1, 0};
    vector<vector<int>> pac, atl;
    
    void getAns2(vector<vector<int>>& hig, vector<vector<int>>& ocean, int i, int j){
        int n = hig.size(); int m = hig[0].size();
        ocean[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while(!q.empty()){
            auto e = q.front(); q.pop();
            int val = hig[e.first][e.second];
            for(int i=0; i<4; i++){
                int x = e.first + dir[i]; int y = e.second + dir[i+1];
                if(x>=0 and y>=0 and x<n and y<m and hig[x][y] >= val and ocean[x][y] == 0){
                    q.push({x, y});
                    ocean[x][y] = 1;
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(); int m = heights[0].size();
        
        pac.resize(n, vector<int> (m, 0));
        atl.resize(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            getAns2(heights, pac, i, 0);
            getAns2(heights, atl, i, m-1);
        }
        
        for(int j=0; j<m; j++){
            getAns2(heights, pac, 0, j);
            getAns2(heights, atl, n-1, j);
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] == 1 and atl[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};
