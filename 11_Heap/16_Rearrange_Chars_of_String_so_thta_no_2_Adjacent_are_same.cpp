// This is the solution where we are fist counting the character frequencies and then storing them into the priority_queue and then taking character out
// of the maxheap and inserting in the answer. While removing the charcter we are making sure that the removed character is not same as the back of the 
// string. If the character is same then we are popping that element for some time and inserting the next frequent element. Then pushing thqat element 
// again into the pq.


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
