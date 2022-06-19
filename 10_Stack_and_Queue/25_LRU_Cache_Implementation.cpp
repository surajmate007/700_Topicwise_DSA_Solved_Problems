// This is the easiest implementation of this problem. BUT giving TLE.

class LRUCache{
    private:
    
    public:
    //Constructor for initializing the cache capacity with the given value.
    int n;
    unordered_map<int, pair<int, int>> mp;
    
    LRUCache(int cap){
        mp.clear();
        n = cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key){
        if(mp.find(key) != mp.end()){
            mp[key] = {mp[key].first, 0};
            for(auto& e : mp){
                e.second.second++;
            }
            return mp[key].first;
        }
        
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value){
        mp[key] = {value, 0};

        int mxkey = INT_MIN; int mxval = INT_MIN;
        for(auto& e : mp){
            e.second.second++;
            if(e.second.second > mxval){
                mxval = e.second.second;
                mxkey = e.first;
            }
        }
        
        if(mp.size() > n){
            mp.erase(mxkey);
        }
    }
};
