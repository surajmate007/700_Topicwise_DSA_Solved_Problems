// The problem link is : https://practice.geeksforgeeks.org/contest/job-a-thon-11-hiring-challenge/problems/#
// This problem is from GFG hiring challenge.

class Solution {
  public:
  
    void dijkstra(int n, vector<vector<int>> adj[], vector<long long>& dist, int s){
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        dist[s] = 0;
        q.push({dist[s], s});
        
        while(!q.empty()){
            auto pr = q.top();
            long long e = pr.second; long long d = pr.first;
            q.pop();
            for(auto k : adj[e]){
                long long x = k[0]; long long y = k[1];
                if(dist[x] > d + y){
                    dist[x] = d + y;
                    q.push({dist[x], x});
                }
            }
        }
    }
  
    long long minimumCost(int n, int m, int x, vector<int> &a, vector<vector<int>> &b){
        set<vector<int>> st;
        for(int i=0; i<m; i++){
            st.insert(b[i]);
        }
        
        vector<vector<int>> adj[n];
        
        for(auto e : st){
            int cost = a[e[0]-1] + a[e[1]-1];
            adj[e[0]-1].push_back({e[1]-1, cost});
            adj[e[1]-1].push_back({e[0]-1, cost});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        dijkstra(n, adj, dist, 0);
        
        return min(dist[n-1], (long long) x+a[0]+a[n-1]);
    }
};
