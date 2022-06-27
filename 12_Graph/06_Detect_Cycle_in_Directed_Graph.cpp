// This is simple solution based on dfs.
// we need 2 different arrays for finding the loop in directed graph.
// Better expalined here : https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12


class Solution {
  public:
    
    bool getAns(int p, vector<int> adj[], int vis[], int dvis[]){
        vis[p] = 1;
        dvis[p] = 1;
        
        for(int i=0; i<adj[p].size(); i++){
            int e = adj[p][i];
            if(vis[e] == 0){
                if(getAns(e, adj, vis, dvis) == true){
                    return true;
                }
            }
            else{
                if(dvis[e] == 1){
                    return true;
                }
            }
        }
        
        dvis[p] = 0;
        return false;
    }
    
    bool isCyclic(int n, vector<int> adj[]) {
        int vis[n];
        int dvis[n];
        memset(vis, 0, sizeof(vis));
        memset(vis, 0, sizeof(dvis));
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                if(getAns(i, adj, vis, dvis) == true){
                    return true;
                }
            }
        }
        return false;
    }
};
