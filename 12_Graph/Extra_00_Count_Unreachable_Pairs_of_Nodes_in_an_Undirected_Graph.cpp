// This problem is solved using both BFS and DFS.
// Very good contest problem.
// Problem Link : https://leetcode.com/contest/biweekly-contest-81/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

class Solution {
public:
    
    int bfs(int p, vector<int> adj[], vector<int>& vis){
        queue<int> q;
        q.push(p);
        vis[p] = 1; int nw = 1;
        
        while(!q.empty()){
            int e = q.front(); q.pop();
            for(int i=0; i<adj[e].size(); i++){
                int v = adj[e][i];
                if(vis[v] == 0){
                    q.push(v);
                    nw++;
                    vis[v] = 1;
                }
            }
        }
        return nw;
    }
    
    void dfs(int p , vector<int> adj[], vector<int>& vis, int& nw){
        nw++;
        vis[p] = 1;
        for(int i=0; i<adj[p].size(); i++){
            int v = adj[p][i];
            if(vis[v] == 0){   
                dfs(v, adj, vis, nw);
            }
        }
        
        return;
    }
    
    
    long long countPairs(int n, vector<vector<int>>& arr) {
        long long last = 0;
        vector<int> adj[n];
        long long ans = 0; long long nw = 0;
        
        for(int i=0; i<arr.size(); i++){
            int a = arr[i][0]; int b = arr[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(n, 0);
        
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                int nw = 0;
                // nw = bfs(i, adj, visited);
                dfs(i, adj, visited, nw);
                
                ans += (nw * last);
                last += nw;
            }
        }
        
        return ans;
    }
};
