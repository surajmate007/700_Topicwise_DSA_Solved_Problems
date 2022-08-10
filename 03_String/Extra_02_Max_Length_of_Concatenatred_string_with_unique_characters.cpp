class Solution {
public:

    bool canAdd(string s2, unordered_map<char, int>& mp){
        unordered_map<char, int> temp;
        for(int j=0; j<s2.length(); j++){
            if(mp.find(s2[j]) != mp.end() or temp.find(s2[j]) != temp.end()){
                return false;
            }
            temp[s2[j]]++;
        }        
        return true;
    }
    
    void add(string s2, unordered_map<char, int>& mp){
        for(int i=0; i<s2.length(); i++){
            mp[s2[i]]++;
        }
    }
    
    void clear(string s2, unordered_map<char, int>& mp){
        for(int i=0; i<s2.length(); i++){
            mp.erase(s2[i]);
        }
    }
    
    int getAns(vector<string>& arr, int n, int idx, unordered_map<char, int>& mp){
        if(idx >= n){
            return 0;
        }
        
        int ans1 = 0;
        int ans2 = 0;
        
        if(canAdd(arr[idx], mp)){
            add(arr[idx], mp);
            ans1 = arr[idx].length() + getAns(arr, n, idx+1, mp);
            clear(arr[idx], mp);
        }
        
        ans2 = getAns(arr, n, idx+1, mp);
        
        return max(ans1, ans2);
    }
    
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        unordered_map<char, int> mp;
        
        return getAns(arr, n, 0, mp);
    }
};
