// This is the simple solution which is based on counting the number of connected components in the cluster and edges present in the cluster.
// Number of edges present in thr cluster ca be easily counted by incrementing inside for loop. After finding the number of edges we will divide it by 2.
// to avoid repeated count of the edges.
// we aill increment extra cabes availabl;e by fidinig the difference between the nodes and edges count. We will also keep on counting the seperated
// componenets in the graph and at last we will check whether the extra cables available are less than the seperated components. If it is then return -1
// else return seperated-1.

class Solution {
public:
    pair<int, int> bfs(int p, vector<int>& vis, vector<int> adj[]){
        queue<int> q; int nds = 1; int edges = 0;
        q.push(p); vis[p] = 1;
        
        while(!q.empty()){
            int a = q.front(); q.pop();
            for(auto e : adj[a]){
                edges++;
                if(vis[e] == 0){
                    nds++;
                    vis[e] = 1;
                    q.push(e);
                }
            }
        }
        
        return {nds, edges};
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0; i<connections.size(); i++){
            int a = connections[i][0]; int b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n, 0);
        int extra = 0; int seperated = 0;
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                auto pr = bfs(i, vis, adj);
                int nodes = pr.first; int edges = pr.second;
                edges /= 2;
                extra += (edges-nodes+1);
                seperated++;
                // cout<<nodes<<" "<<edges<<" "<<extra<<" "<<seperated<<endl;
            }
        }
        
        if(extra+1 < seperated){
            return -1;
        }
        
        return seperated-1;
    }
};
