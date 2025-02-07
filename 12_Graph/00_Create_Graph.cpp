// A graph is a data structure that consists of the following two components: 
// 1. A finite set of vertices also called as nodes. 
// 2. A finite set of ordered pair of the form (u, v) called as edge. The pair is ordered because (u, v) is not the same as (v, u) in case of a directed
// graph(di-graph). The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. The edges may contain weight/value/cost.
// Graphs are used to represent many real-life applications: Graphs are used to represent networks. The networks may include paths in a city or telephone
// network or circuit network. Graphs are also used in social networks like linkedIn, Facebook. For example, in Facebook, each person is represented
// with a vertex(or node). Each node is a structure and contains information like person id, name, gender, and locale. See this for more applications
// of graph. Following is an example of an undirected graph with 5 vertices. 

// The following two are the most commonly used representations of a graph. 
// 1. Adjacency Matrix 
// 2. Adjacency List 
// There are other representations also like, Incidence Matrix and Incidence List. The choice of graph representation is situation-specific. It totally
// depends on the type of operations to be performed and ease of use. 
// Adjacency Matrix: 
// Adjacency Matrix is a 2D array of size V x V where V is the number of vertices in a graph. Let the 2D array be adj[][], a slot adj[i][j] = 1 indicates
// that there is an edge from vertex i to vertex j. Adjacency matrix for undirected graph is always symmetric. Adjacency Matrix is also used to represent
// weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w. 

// The adjacency matrix for the above example graph is: 

// Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex ‘u’ to
// vertex ‘v’ are efficient and can be done O(1).
// Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2)
// time.  Computing all neighbors of a vertex takes O(V) time (Not efficient).

// Adjacency List: 
// An array of lists is used. The size of the array is equal to the number of vertices. Let the array be an array[]. An entry array[i] represents the list
// of vertices adjacent to the ith vertex. This representation can also be used to represent a weighted graph. The weights of edges can be represented
// as lists of pairs. Following is the adjacency list representation of the above graph.

// Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in a graph thus consuming O(V^2) space. Adding a vertex is
// easier. Computing all neighbors of a vertex takes optimal time.
// Cons: Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done O(V).
// In Real-life problems,  graphs are sparse(|E| <<|V|2). That’s why adjacency lists Data structure is commonly used for storing graphs. Adjacency
// matrix will enforce (|V|2) bound on time complexity for such algorithms. 


 // Graph creatio is noting but the graph storage.

// Adjacency Matrix Representation.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	int adj[n+1][n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u][v] = 1; 
	    adj[v][u] = 1; 
	}
	return 0;
}


// Adjacency List Representation.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	return 0;
}



// Adjacency List Representation of weighted Graph.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m ;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<pair<int, int>> adj[n+1]; 
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v, wt; 
	    cin >> u >> v >> wt;
	    adj[u].push_back({v, wt}); 
	    adj[v].push_back({u, wt}); 
	}
	return 0;
}
