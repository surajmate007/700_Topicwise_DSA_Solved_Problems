// This is not the original code it is just telling whether the rearrangement is possible or not.

bool rearrangeString(string str){
        unordered_map<char, int> mp;
        int n = str.length();
        int mxf = 0;
        
        for(int i=0; i<n; i++){
            mp[str[i]]++;
            mxf = max(mxf, mp[str[i]]);
        }
        int rem = n - mxf;
        
        if(rem > mxf){
            return true;
        }
        return false;
}
