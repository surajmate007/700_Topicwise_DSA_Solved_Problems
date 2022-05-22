// Wrote this code but giving TLE: (giving correct results)

string smallestWindow (string s, string p){
        unordered_map<char, int> mp; int m = p.length(); int n = s.length();
        for(int i=0; i<m; i++){
            mp[p[i]] = 0; 
        }
        
        int i=0; int j=0; int si = INT_MAX, ei = INT_MAX; int minlen = INT_MAX; string res;
        int cnt = 0; int t = mp.size();
        while(j < n){
            if(mp.find(s[j]) != mp.end() and mp[s[j]]==0){
                mp[s[j]] = 1;
                cnt++;
            }
            else if(mp.find(s[j]) != mp.end() and mp[s[j]] > 0){
                mp[s[j]]++;
            }
            j++;
            
            if(cnt == t){
                while((mp.find(s[i]) != mp.end() and mp[s[i]] > 1) or (mp.find(s[i]) == mp.end())){
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]--;
                    }
                    i++;
                    if(minlen > j-i){
                        minlen = j-i; si = i; ei = j;
                    }   
                }
            }
        }
        
        if(minlen == INT_MAX){
            return "-1";
        }
        res = s.substr(si, minlen);
        return res;
    }

//
