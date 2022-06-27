// We have to only find all the nodes that are reachable from 0.

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void getAns(int p, vector<int> adj[], vector<int>& vis, vector<int>& ans){
        queue<int> q;
        q.push(p); vis[p] = 1;
        ans.push_back(p);
        int t = 0;
        while(!q.empty()){
            int e = q.front(); q.pop();
            for(int i=0; i<adj[e].size(); i++){
                int k = adj[e][i];
                if(vis[k] == 0){
                    q.push(k);
                    vis[k] = 1;
                    ans.push_back(k);
                    t++;
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V, 0);
        getAns(0, adj, visited, ans);
        
        return ans;
    }
};
