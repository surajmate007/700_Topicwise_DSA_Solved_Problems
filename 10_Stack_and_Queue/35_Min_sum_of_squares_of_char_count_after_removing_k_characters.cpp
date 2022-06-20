// Simple approach using priority queue.

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for(auto e : mp){
            pq.push({e.second, e.first});
        }
        
        while(k--){
            int val = pq.top().first-1;
            char ch = pq.top().second;
            pq.pop();
            pq.push({val ,ch});
        }
        
        int ans = 0;
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            ans += (e.first * e.first);
        }
        
        return ans;
    }
};
