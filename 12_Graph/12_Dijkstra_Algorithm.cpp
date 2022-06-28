// Simple Dijkstra algorithm implementation.
// This is based on greedy approach of finding the distances from one of the source node to all the other nodes.
// Thus this is single source shortest path problem.


 // } Driver Code Ends
class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s){
        vector<int> dist(n, 1e9);
        queue<int> q;
        q.push(s);
        dist[s] = 0;
        
        while(!q.empty()){
            int e = q.front();
            q.pop();
            for(auto k : adj[e]){
                int x = k[0]; int y = k[1];
                if(dist[x] > dist[e] + y){
                    dist[x] = dist[e] + y;
                    q.push(x);
                }
            }
        }
        return dist;
    }
};
