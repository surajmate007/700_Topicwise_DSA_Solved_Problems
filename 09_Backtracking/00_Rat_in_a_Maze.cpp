// The solution is approach is simple as like N queens problem.

class Solution{
    public:
    void getPath(vector<vector<int>>& m, int n, int i, int j, string ds, vector<string>& ans){
        if(i<0 or j<0 or i>=n or j>=n){
            return;
        }
        
        if(m[i][j] == 0){
            return;
        }
        
        if(i==n-1 and j==n-1){
            ans.push_back(ds);
            return;
        }
        
        m[i][j] = 0;
        
        getPath(m, n, i+1, j, ds+'D', ans);
        getPath(m, n, i, j+1, ds+'R', ans);
        getPath(m, n, i-1, j, ds+'U', ans);
        getPath(m, n, i, j-1, ds+'L', ans);
        
        m[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        getPath(m, n, 0, 0, "", ans);
        
        return ans;
    }
};



