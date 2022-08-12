// easy solution revise frequently.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool getAns(int src, int k, vector<pair<int, int>> adj[], vector<int>& vis){
    vis[src] = 1;
    if(k<0){
        return true;
    }
    
    for(auto e : adj[src]){
        int d = e.first; int w = e.second;
        if(vis[d] == 0){
            if((getAns(d, k-w, adj, vis) == true)){
                return true;
            }
        }
    }
    
    vis[src] = 0;
    return false;
}

string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges){
    vector<pair<int, int>> adj[n];
    for(int i=0; i<m; i++){
        int a = edges[i][0]; int b = edges[i][1]; int w = edges[i][2];
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    
    vector<int> vis(n, 0);
    if(getAns(0, k, adj, vis) == true){
        return "YES";
    }
    return "NO";
}
