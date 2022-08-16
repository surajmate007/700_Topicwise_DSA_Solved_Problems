// Naive Approach: A simple approach is to one by one remove all edges and see if removal of an edge causes disconnected graph. Following are steps
// of simple approach for connected graph.

// For every edge (u, v), do following :

// Remove (u, v) from graph 
// See if the graph remains connected (We can either use BFS or DFS) 
// Add (u, v) back to the graph.
// Time Complexity: O(E*(V+E)) for a graph represented using adjacency list.

// Efficient Approach.
// Better explained here : https://www.youtube.com/watch?v=2rjZH0-2lhk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) {			// This is the standard formula stating if low of adjacent is greater than the time of insertion of 
                                           		// the node then it will be the bridge. 
                cout << node << " " << it << endl;
            }
		
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0); 
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}
