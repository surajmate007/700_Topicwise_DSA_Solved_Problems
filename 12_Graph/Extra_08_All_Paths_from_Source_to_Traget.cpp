// Easy solution using dfs.

class Solution {
public:
    
    void getAns(int src, int dst, vector<int>& ds, vector<int>& vis, vector<vector<int>>& graph, vector<vector<int>>& ans){
        vis[src] = 1;
        ds.push_back(src);
        
        if(src == dst){
            ans.push_back(ds);
            vis[src] = 0;
            ds.pop_back();
            return;
        }
        
        for(auto d : graph[src]){
            if(vis[d] == 0){
                getAns(d, dst, ds, vis, graph, ans);
            }
        }
        
        vis[src] = 0;
        ds.pop_back();
    }   
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(n, 0);
        
        getAns(0, n-1, ds, vis, graph, ans);
        
        return ans;
    }
};
