// Solved by me:
// Here I am using unordered map to keep track of all the elements which are within the cache and we are continuously increating the counter corresponding
// to each element. At every instant we are counting the size of the map. If the map size exceeds the C value then we have to delete the element
// with max counter. Also when the elememts are already there in the map and repeating then have to resent the counter of such element.

class Solution{
public:
    int pageFaults(int N, int C, int a[]){
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int i=0; i<N; i++){
            if(mp.find(a[i]) == mp.end()){
                ans++;
            }
            int mc = 0; int mv = INT_MIN;
            for(auto& e : mp){
                if(e.second > mc){
                    mc = e.second;
                    mv = e.first;
                }
                e.second++;
            }
            mp[a[i]] = 1;
            
            if(mp.size() > C){
                mp.erase(mv);
            }
        }
        
        return ans;
    }
};
