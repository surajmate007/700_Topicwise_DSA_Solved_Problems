// sOLUTION USING PRIORITY QUEUE.
// We are considering most frequent elements from the queue and then adding it to the answer string if and only if this elements is not present at the 
// back of the string.
// If it is present at the back of the string the stirng then we are looking for the other remaining elements in the queue which we can add in our answer.

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        
        for(auto e : mp){
            pq.push({e.second, e.first});
        }
        
        string ans = "";
        while(!pq.empty()){
            char ch = pq.top().second;
            if(ch == ans.back()){
                int val = pq.top().first;
                pq.pop();
                
                if(pq.empty()){
                    return "";
                }
                
                char nch = pq.top().second;
                int nval = pq.top().first-1;
                pq.pop();
                ans += nch;
                
                if(nval != 0){
                    pq.push({nval, nch});
                }
                
                pq.push({val, ch});
                continue;
            }
            
            ans += ch;
           
            int val = pq.top().first - 1;
            pq.pop();
            if(val != 0){
                pq.push({val, ch});
            }
        }
        
        return ans;
    }
};
