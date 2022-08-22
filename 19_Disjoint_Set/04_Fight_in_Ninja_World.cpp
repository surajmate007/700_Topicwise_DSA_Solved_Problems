#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mx = 1e5 + 5;
int nodes, one = 0, zero = 0;

vector<ll> adj[mx];
vector<bool> vis(mx, false);

void clearAll() {
    for(int i = 0; i < mx; i++) {
        vis[i] = false;
        adj[i].clear();
    }
}

void dfs(int curr, int col) {
    if(vis[curr]) return;
    vis[curr] = true;
    if(col) one++;
    else zero++;
    for(auto child : adj[curr]) {
        if(!vis[child]) {
            dfs(child, col ^ 1);
        }
    }
}

void solve(int x) {
    int edges;
    cin >> edges;

    // this array is just to check if the node is present in the graph or not!

    vector<bool> arr(mx, false);
    nodes = -1;

    while(edges--) {
        int a, b;
        cin >> a >> b;
        arr[a] = arr[b] = true;
        nodes = max({nodes, a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
    for(int i = 1; i <= nodes; i++) {
        if(!vis[i] && arr[i]) {
            one = 0, zero = 0;
            dfs(i, 0);
            ans += max(one, zero);
        }
    }

    cout << "Case " << x << ": " << ans << '\n';
    clearAll();
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        solve(i);
    }
}
