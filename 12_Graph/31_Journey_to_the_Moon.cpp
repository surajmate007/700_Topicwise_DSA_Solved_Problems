// Exactly same question as solved in the contest.
// we have to find the number of pairs that can be formed from disconnected components.

long long bfs(int p, vector<int>& vis, vector<int> adj[]){
    queue<int> q;
    q.push(p);
    long long ans = 1;
    
    while(!q.empty()){
        int k = q.front(); q.pop();
        for(auto e : adj[k]){
            if(vis[e] == 0){
                vis[e] = 1;
                q.push(e);
                ans++;
            }
        }
    }
    return ans;
}

int journeyToMoon(int n, vector<vector<int>> ast) {
    vector<int> adj[n];
    for(int i=0; i<ast.size(); i++){
        int a = ast[i][0]; int b = ast[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    vector<int> vis(n, 0);
    long long cnt = 0; long long last = 0;
    long long ans = 0;
    
    for(int i=0; i<n; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            cnt = bfs(i, vis, adj);
            ans += (cnt*last);
            cout<<cnt<<" "<<last<<endl;
            last += cnt;
        }
    }
    return ans;
}
