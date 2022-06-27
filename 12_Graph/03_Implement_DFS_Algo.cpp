// Simple DFS Implementation.

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int p, vector<int> adj[], vector<int>& vis, vector<int>& ans){
        ans.push_back(p);
        vis[p] = 1;
        
        for(int i=0; i<adj[p].size(); i++){
            int e = adj[p][i];
            if(vis[e] == 0){
                dfs(e, adj, vis, ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> ans;
        vector<int> vis(n, 0);
        
        dfs(0, adj, vis, ans);
        
        return ans;
    }
};
