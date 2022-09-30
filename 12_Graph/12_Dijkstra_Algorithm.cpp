// Simple Dijkstra algorithm implementation.
// This is based on greedy approach of finding the distances from one of the source node to all the other nodes.
// Thus this is single source shortest path problem.

// Given a graph and a source vertex in the graph, find the shortest paths from the source to all vertices in the given graph.
// Dijkstra’s algorithm is very similar to Prim’s algorithm for minimum spanning tree. Like Prim’s MST, we generate a SPT (shortest path tree) with a given
// source as a root. We maintain two sets, one set contains vertices included in the shortest-path tree, other set includes vertices not yet included in the
// shortest-path tree. At every step of the algorithm, we find a vertex that is in the other set (set of not yet included) and has a minimum distance
// from the source.
// Below are the detailed steps used in Dijkstra’s algorithm to find the shortest path from a single source vertex to all other vertices in the given graph.

// Algorithm 
// 1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in the shortest-path tree, i.e., whose minimum distance from
// the source is calculated and finalized. Initially, this set is empty. 
// 2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source
// vertex so that it is picked first. 
// 3) While sptSet doesn’t include all vertices 
// ….a) Pick a vertex u which is not there in sptSet and has a minimum distance value. 
// ….b) Include u to sptSet. 
// ….c) Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex
// v, if the sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v. 

// The set sptSet is initially empty and distances assigned to vertices are {0, INF, INF, INF, INF, INF, INF, INF} where INF indicates infinite. Now pick
// the vertex with a minimum distance value. The vertex 0 is picked, include it in sptSet. So sptSet becomes {0}. After including 0 to sptSet, update
// distance values of its adjacent vertices. Adjacent vertices of 0 are 1 and 7. The distance values of 1 and 7 are updated as 4 and 8. The following
// subgraph shows vertices and their distance values, only the vertices with finite distance values are shown. The vertices included in SPT are shown
// in green colour.
 
// Pick the vertex with minimum distance value and not already included in SPT (not in sptSET). The vertex 1 is picked and added to sptSet. So sptSet
// now becomes {0, 1}. Update the distance values of adjacent vertices of 1. The distance value of vertex 2 becomes 12.

// Notes: 
// 1) The code calculates the shortest distance but doesn’t calculate the path information. We can create a parent array, update the parent array when
// distance is updated (like prim’s implementation) and use it to show the shortest path from source to different vertices.
// 2) The code is for undirected graphs, the same Dijkstra function can be used for directed graphs also.
// 3) The code finds the shortest distances from the source to all vertices. If we are interested only in the shortest distance from the source to a single
// target, we can break the for loop when the picked minimum distance vertex is equal to the target (Step 3.a of the algorithm).
// 4) Time Complexity of the implementation is O(V^2). If the input graph is represented using adjacency list, it can be reduced to O(E log V) with the
// help of a binary heap. Please see 
// Dijkstra’s Algorithm for Adjacency List Representation for more details.
// 5) Dijkstra’s algorithm doesn’t work for graphs with negative weight cycles. It may give correct results for a graph with negative edges but you must
// allow a vertex can be visited multiple times and that version will lose its fast time complexity. For graphs with negative weight edges and cycles,
// Bellman–Ford algorithm can be used, we will soon be discussing it as a separate post.


class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s){
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        dist[s] = 0;
        pq.push({dist[s], s});
        
        while(!pq.empty()){
            auto pr = pq.top();
            int e = pr.second; int d = pr.first;
            pq.pop();
            for(auto k : adj[e]){
                int x = k[0]; int y = k[1];
                if(dist[x] > d + y){
                    dist[x] = d + y;
                    pq.push({dist[x], x});
                }
            }
        }
        return dist;
    }
};
