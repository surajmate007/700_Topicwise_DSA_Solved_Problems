// In topological sort we arer using stack where we only store the entry after going over the node.
// Better explained here : https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13

// Using DFS:

class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	void getAns(int p, vector<int> adj[], vector<int>& vis, stack<int>& st){
	    vis[p] = 1;
	    
	    for(int i=0; i<adj[p].size(); i++){
	        int e = adj[p][i];
	        if(vis[e] == 0){
	            getAns(e, adj, vis, st);
	        }
	    }
	    st.push(p);
	}
	
	vector<int> topoSort(int n, vector<int> adj[]){
	    vector<int> vis(n, 0);
	    stack<int> st;
	    
	    for(int i=0; i<n; i++){
	        if(vis[i] == 0){
	            getAns(i, adj, vis, st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};


// Using BFS (Kahn's Algorithm)


class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	
	vector<int> topoSort(int n, vector<int> adj[]){

	    int indgre[n];
	    memset(indgre, 0, sizeof(indgre));
	    
	    for(int i=0; i<n; i++){
	        for(auto e : adj[i]){
	            indgre[e]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> ans;
	    
	    for(int i=0; i<n; i++){
	        if(indgre[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int p = q.front(); q.pop();
	        ans.push_back(p);
	        
	        for(auto e : adj[p]){
    	        indgre[e]--;
    	        if(indgre[e] == 0){
    	            q.push(e);
    	        }
    	    }
	    }
	    
	    return ans;
	}
};
