// solved using DFS:
// Modification of cycle detection in directed graph.

class Solution {
public:

    int ans = 0;

    void getAns(int src, int length, vector<int>& adj, vector<int>& vis, vector<int>& dvis, vector<int>& dist){
        vis[src] = 1;
        dvis[src] = 1;

        dist[src] = length;
        int next = adj[src];

        if(next == -1){
            dvis[src] = 0;
            return;
        }
        
        if(vis[next] == 0){
            getAns(next, length+1, adj, vis, dvis, dist);
        }
        else{
            if(dvis[next] == 1){
                ans = max(ans, length - dist[next] + 1);
            }
        }

        dvis[src] = 0;
    }


    int longestCycle(vector<int>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), dvis(n, 0);
        vector<int> dist(n, 0);
        ans = 0;

        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                getAns(i, 0, adj, vis, dvis, dist);
            }
        }
        
        if(ans == 0){
            return -1;
        }

        return ans;
    }
};
