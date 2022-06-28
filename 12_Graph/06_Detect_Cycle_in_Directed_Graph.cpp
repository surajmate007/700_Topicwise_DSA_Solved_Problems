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


// Cycle detection using Kahns algorithm using BFS.
// We know topological sort is not possible for cyclic graph. Hence if there is cycle in the graph then all nodes will not be included in the
// topologocal sort. Thus if the count value is less than n means cycle is present in the graph.


class Solution {
  public:
    
    bool isCyclic(int n, vector<int> adj[]) {
        int indgre[n];
	    memset(indgre, 0, sizeof(indgre));
	    
	    for(int i=0; i<n; i++){
	        for(auto e : adj[i]){
	            indgre[e]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0; i<n; i++){
	        if(indgre[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    int cnt = 0;
	    
	    while(!q.empty()){
	        int p = q.front(); q.pop();
	        cnt++;
	        
	        for(auto e : adj[p]){
    	        indgre[e]--;
    	        if(indgre[e] == 0){
    	            q.push(e);
    	        }
    	    }
	    }
	    
	    if(cnt == n){
	        return false;
	    }
	    
	    return true;
    }
};
