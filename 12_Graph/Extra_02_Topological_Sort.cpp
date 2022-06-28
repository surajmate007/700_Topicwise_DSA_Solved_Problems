// In topological sort we arer using stack where we only store the entry after going over the node.

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
