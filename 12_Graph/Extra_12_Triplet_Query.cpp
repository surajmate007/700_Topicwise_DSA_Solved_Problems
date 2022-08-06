// revise frequently.

class Solution {
  public:
  
  void dfs(int node, vector<int> adj[], vector<int>& vis, string& col, set<char>& st){
      vis[node] = 1;
      
      for(auto e : adj[node]){
          
          // if colours are same:
          if(!vis[e] and col[node] == col[e]){
              dfs(e, adj, vis, col, st);
          }
          
          // if colours are different:
          else if(col[node] != col[e]){
              st.insert(col[e]);
          }
      }
  }
  
    vector<string> solve(int n, int m, int q, string col, vector<vector<int>> &edges, vector<string> &query){
        vector<int> adj[n];
        for(auto e : edges){
            int a = e[0]; int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int> vis(n, 0);
        int dp[26][26][26] = {0};
        
        for(int i=0; i<n; i++){
            if(vis[i] == 0){
                set<char> st;
                dfs(i, adj, vis, col, st);
            
                for(auto it1 : st){
                    for(auto it2 : st){
                        dp[col[i]-'a'][it1-'a'][it2-'a'] = 1;
                    }
                }
            }
        }
        
        vector<string> ans;
        for(auto e : query){
            char a = e[0]-'a', b = e[1]-'a', c = e[2]-'a';
            if(dp[a][b][c]||dp[a][c][b]||dp[b][a][c]||dp[b][c][a]||dp[c][a][b]||dp[c][b][a]){
                ans.push_back("YES");
            }
            else{
                ans.push_back("NO");
            }
        }
        
        return ans;
    }
};
