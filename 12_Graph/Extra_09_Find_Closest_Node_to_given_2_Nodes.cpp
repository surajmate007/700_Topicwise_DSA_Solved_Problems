// using Dijkstra Algo from both the nodes and then traversing over the distance aray to find the closest distance from both these nodes.

class Solution {
public:
    
    void dijks(int src, int n, vector<pair<int, int>> adj[], vector<int>& dist){
        dist[src] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto e = pq.top(); pq.pop();
            int s = e.second; int d1 = e.first;
            
            for(auto neg : adj[s]){
                int dst = neg.first;
                if(dist[dst] > d1 + 1){
                    dist[dst] = d1 + 1;
                    pq.push({d1 + 1, dst});
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<pair<int, int>> adj[n];
        for(int i=0; i<n; i++){
            if(edges[i] != -1){
                adj[i].push_back({edges[i], 1});
            }
        }
        
        vector<int> dist1(n, 1e9), dist2(n, 1e9);
        dijks(node1, n, adj, dist1);
        dijks(node2, n, adj, dist2);
        
        int ans = 1e8;
        int node = -1;
        
        for(int i=0; i<n; i++){
            if(ans > max(dist1[i], dist2[i])){
                ans = max(dist1[i], dist2[i]);
                node = i;
            }
        }

        return node;
    }
};
