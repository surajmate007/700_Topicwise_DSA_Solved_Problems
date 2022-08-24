// This problem is solved by me using multiset and DSU:
// DSU datastructure is very important in solving problems of distributed segments.

class Solution {
public:
    
    vector<long long> parent, sum;
    multiset<long long> mst;
    
    void make(int v){
        parent[v] = v;
        sum[v] = 0;
        mst.insert(0);
    }
    
    int find(int v){
        if(parent[v] == v){
            return v;
        }
        return find(parent[v]);
    }
    
    void Union(int a, int b){
        a = find(a); b = find(b);
        if(a != b){
            parent[b] = a;
            
            auto it = mst.find(sum[b]);
            mst.erase(it);
            it = mst.find(sum[a]);
            mst.erase(it);
            sum[a] += sum[b];
            mst.insert(sum[a]);
        }
    }
    
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        parent.resize(n+1);
        sum.resize(n+1);
        mst.clear();
        
        for(int i=1; i<=n; i++){
            make(i);
        }
        vector<long long> ans;
        
        for(int i=n-1; i>=0; i--){
            int rm = removeQueries[i]+1;
            ans.push_back(*(--mst.end()));
            
            auto it = mst.find(sum[rm]);
            mst.erase(it);
            sum[rm] = nums[rm-1];
            mst.insert(sum[rm]);
            
            // cout<<"mst1 : "<<*(--mst.end())<<endl;
            if(rm > 1 and sum[rm-1] != 0){
                Union(rm , rm-1);
            }
            if(rm < n and sum[rm+1] != 0){
                Union(rm, rm+1);
            }
            // cout<<"mst2 : "<<*(--mst.end())<<endl;
            
            // for(int i=1; i<=n; i++){
            //     cout<<sum[i]<<" ";
            // }
            // cout<<endl;
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
