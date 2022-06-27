// This is the simple solution to find the cycle in the graph.
// in this we are storing the node as well as its adjacent node in the queue. When the node is already visited then we will check whether the
// current node fro where we reach to this already visited node is stored as adjacent node in the queue or not. If it is then this is not the cycle
// But if the adjacent node strored is different and this node is diferent then we can see that we are reaching to the same node from multiple nodes
// hence cycle will be present.

class Solution{
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int p, vector<int> adj[], vector<int>& vis){
        queue<pair<int, int>> q;
        q.push({p, -1});
        vis[p] = 1;
        
        while(!q.empty()){
            int v = q.front().first; int prev = q.front().second; q.pop();
            for(int i=0; i<adj[v].size(); i++){
                int e = adj[v][i];
                if(vis[e] == 0){
                    q.push({e, v});
                    vis[e] = 1;
                }
                else{
                    if(e != prev and prev != -1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    
    bool isCycle(int n, vector<int> adj[]) {
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(bfs(i, adj, vis) == true){
                return true;
            }
        }
        
        return false;
    }
};
