// revise frequently.

class DSU{
public:
    vector<int>siz;
    vector<int>par;
    DSU(int n){
        for(int i = 0;i < n;i++){
            par.push_back(i);
            siz.push_back(1);
        }
    }
    int findPar(int node){
        if(par[node] == node)return node;
        return par[node] = findPar(par[node]);
    }
    void join(int u,int v){
        int paru = findPar(u);
        int parv = findPar(v);
        if(siz[paru] >= siz[parv]){
            siz[paru] += siz[parv];
            par[parv] = paru;
        }
        else{
            siz[parv] += siz[paru];
            par[paru] = parv;
        }
    }
};


class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = n;
        if(n == 1)return 1;
        if(n == 2){
            if(vals[0] == vals[1])return 3;
            return 2;
        }
        DSU dsu(n);
        auto comp = [&](vector<int>& v1,vector<int>& v2)-> bool {
            int m1 = max(vals[v1[0]],vals[v1[1]]);
            int m2 = max(vals[v2[0]],vals[v2[1]]);
            if(m1 < m2)return true;
            return false;
        };
        vector<pair<int,int>>vl;
        for(int i = 0;i < n;i++){
            vl.push_back({vals[i],i});
        }
        sort(vl.begin(),vl.end());
        sort(edges.begin(),edges.end(),comp);
        int edit = 0;
        for(int i = 0;i < n;i++){
            int j = i;
            while(j+1 < n && vl[j].first == vl[j+1].first){
                j++;
            }
            int curr_val = max(vals[edges[edit][0]],vals[edges[edit][1]]);
            while(curr_val <= vl[i].first && edit < n-1){
                dsu.join(edges[edit][0],edges[edit][1]);
                edit++;
                if(edit < n-1){
                    curr_val = max(vals[edges[edit][0]],vals[edges[edit][1]]);
                }
                else{
                    curr_val = INT_MAX;
                }
            }
            map<int,int>um;
            for(int k = i;k <= j;k++){
                um[dsu.findPar(vl[k].second)]++;
            }
            for(auto it = um.begin();it != um.end();it++){
                if(it->second > 1){
                    ans += (it->second*(it->second-1))/2;
                }
            }
            i = j;
        }
        return ans;
    }
};
