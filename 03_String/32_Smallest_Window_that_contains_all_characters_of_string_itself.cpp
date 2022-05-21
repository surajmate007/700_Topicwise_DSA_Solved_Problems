// Brute force approach giving TLE

int findSubString(string str){
        set<char> st; int n = str.length();
        
        for(int i=0; i<n; i++){
            st.insert(str[i]);
        }
        int p = st.size();
        int ans = INT_MAX;
        bool flag = false;
        for(int i=0; i<n; i++){
            set<char> ch;
            for(int j=i+p-1; j<n; j++){
                for(int k=i; k<=j; k++){
                    ch.insert(str[k]);
                    if(ch.size() == p){
                        ans = min(ans, j-i+1);
                        break;
                    }
                }
                if(ch.size() == p){
                    break;
                }
            }
        }
        
        return ans;
        
}

// More efficient code a version of Sliding window technique:


int findSubString(string str){
        
        unordered_map<char, int> mp;
        set<char> st; int n = str.length();
        if(n==1){ return n;}
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            st.insert(str[i]);
            mp[str[i]] = 0;
        }
        int p = st.size();
        
        mp[str[0]] = 1;
        int i=0; int j=1; int cnt = 1;
        while(j < str.length() and i<j){
            if(mp[str[j]] == 0){
                mp[str[j]] = 1;
                cnt++; 
            }
            else{
                mp[str[j]]++;
            }
            j++;
            
            if(cnt == p){
                while(mp[str[i]] > 1){
                    mp[str[i]]--;
                    i++;
                }
                ans = min(ans, j-i);
            }
        }
        return ans;
}
