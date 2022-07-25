// Given a graph and a source vertex src in graph, find shortest paths from src to all vertices in the given graph. The graph may contain negative weight edges. 
// We have discussed Dijkstra’s algorithm for this problem. Dijkstra’s algorithm is a Greedy algorithm and time complexity is O((V+E)LogV) (with the use of
// Fibonacci heap). Dijkstra doesn’t work for Graphs with negative weights, Bellman-Ford works for such graphs. Bellman-Ford is also simpler than Dijkstra
// and suites well for distributed systems. But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra. 

// Algorithm:
// Following are the detailed steps.
// Input: Graph and a source vertex src 
// Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight
// cycle is reported.

// 1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size
// |V| with all values as infinite except dist[src] where src is source vertex.
// 2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph. 
// …..a) Do following for each edge u-v 
// ………………If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
// ………………….dist[v] = dist[u] + weight of edge uv
// 3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v 
// ……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle” 
// The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges
// one more time and get a shorter path for any vertex, then there is a negative weight cycle

// How does this work? Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. It first calculates the
// shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th
// iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why
// the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most
// i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges (Proof is simple, you can refer this or MIT Video
// Lecture)

// Notes:

// Negative weights are found in various applications of graphs. For example, instead of paying cost for a path, we may get some advantage if we follow
// the path.
// Bellman-Ford works better (better than Dijkstra’s) for distributed systems. Unlike Dijkstra’s where we need to find the minimum value of all vertices,
// in Bellman-Ford, edges are considere considereddone by one.                                                                  
// Bellman-Ford does not work with undirected graph with negative edges as it will declared as negative cycle.



#include<bits/stdc++.h>
using namespace std;

struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int N=6,m=7;
    vector<node> edges; 
	edges.push_back(node(0,1,5));
	edges.push_back(node(1,2,-2));
	edges.push_back(node(1,5,-3));
	edges.push_back(node(2,4,3));
	edges.push_back(node(3,2,6));
	edges.push_back(node(3,4,-2));
	edges.push_back(node(5,3,1));
  
    int src=0;
    int inf = 10000000; 
    vector<int> dist(N, inf); 
    dist[src] = 0; 
    
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}





// BellmanFord without using structure:
// Here it is already told that the graph will not have negative cycles hence we dont need to check it by using one extra loop.


class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        int n = adj.size();
        
        for(int i=0; i<V-1; i++){
            for(int j=0; j<n; j++){
                vector<int> e = adj[j];
                int s = e[0]; int d = e[1]; int w = e[2];
                if(dist[s] != 1e8){
                    if(dist[s] + w < dist[d]){
                        dist[d] = dist[s] + w;
                    }
                }
            }
        }
        
        return dist;
    }
};
