// Simple solution based on topological sort where we are first finding the indegree of all the nodes and then at the end we will check whether
// the indegree of all the nodes reduce down to 0 or not.

class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    vector<int> indegree(n, 0);
	    vector<int> adj[n];
	    vector<int> vis(n, 0);
	    int cnt = 0;
	    
	    for(auto e : prerequisites){
	        int a = e.first; int b = e.second;
	        adj[b].push_back(a);
	        indegree[a]++;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<n; i++){
	        if(indegree[i] == 0){
	            q.push(i); vis[i] = 1;
	            cnt++;
	        }
	    }
	    
	    if(q.empty()){
	        return false;
	    }
	    
	    while(!q.empty()){
	        int e = q.front(); q.pop();
	        for(auto k : adj[e]){
	            indegree[k]--;
	            if(indegree[k] == 0){
	                q.push(k);
	            }
	        }
	    }
	    
	    return (accumulate(indegree.begin(), indegree.end(), 0) == 0);
	}
};
