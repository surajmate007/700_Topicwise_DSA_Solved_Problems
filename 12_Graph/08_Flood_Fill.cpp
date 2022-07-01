// Easy solution using BFS technique.

class Solution {
public:
    
    bool isValid(int x, int y, int n, int m, int color, vector<vector<int>> ans, int tochng){
        if(x>=0 and y>=0 and x<n and y<m and ans[x][y] != color and ans[x][y] == tochng){
            return true;
        }
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); int m = image[0].size();
        vector<vector<int>> ans = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int tochng = ans[sr][sc];
        ans[sr][sc] = color;
        
        while(!q.empty()){
            int x = q.front().first; int y = q.front().second;
            q.pop();
            for(auto d : dir){
                int a = d[0]; int b = d[1];
                if(isValid(x+a, y+b, n, m, color, ans, tochng)){
                    ans[x+a][y+b] = color;
                    q.push({x+a, y+b});
                }
            }
        }
        
        return ans;
    }
};
