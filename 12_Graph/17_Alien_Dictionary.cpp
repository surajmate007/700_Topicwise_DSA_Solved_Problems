// This code is based on DFS rechnique and topological sort.
// We are first finding the dependency of characters from the adjacent strings and store this dependency into the adjacncy list and then use topological
// sort on this list to find the order of characters.


class Solution{
    public:
    vector<int> order;
    vector<vector<int>> adj;
    vector<int> vis;
    
    void dfs(int curr){
        vis[curr]=1;
        for (int nxt:adj[curr]){
            if (vis[nxt]==0) dfs(nxt);
        }
        order.push_back(curr);
    }
    
    string findOrder(string dict[], int n, int k) {
        adj.resize(k);
        vis.resize(k,0);
        
        for (int i=0;i<n-1;i++){
            int m=dict[i].size();
            for (int j=0;j<m;j++){
                if (dict[i][j]!=dict[i+1][j]){
                    adj[(int)dict[i][j]-(int)'a'].push_back((int)dict[i+1][j]-(int)'a');
                    break;
                }
            }
        }
        
        int st=(int)dict[0][0]-(int)'a';
        dfs(st);
        
        for (int i=0;i<k;i++){
            if (vis[i]==0) dfs(i);
        }
        
        reverse(order.begin(),order.end());
        string ans="";
        
        for (int i=0;i<k;i++){
            ans.push_back('a'+order[i]);
        }
        
        return ans;
    }
};
