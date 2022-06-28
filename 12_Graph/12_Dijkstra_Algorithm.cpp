// Simple Dijkstra algorithm implementation.
// This is based on greedy approach of finding the distances from one of the source node to all the other nodes.
// Thus this is single source shortest path problem.


class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s){
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
        dist[s] = 0;
        q.push({dist[s], s});
        
        while(!q.empty()){
            auto pr = q.top();
            int e = pr.second; int d = pr.first;
            q.pop();
            for(auto k : adj[e]){
                int x = k[0]; int y = k[1];
                if(dist[x] > d + y){
                    dist[x] = d + y;
                    q.push({dist[x], x});
                }
            }
        }
        return dist;
    }
};
