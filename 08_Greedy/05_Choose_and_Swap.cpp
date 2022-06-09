class Solution{
  public:
    string chooseandswap(string s){
        string p = s;
        
        sort(p.begin(), p.end());
        if(s==p){
            return s;
        }
        
        char one = ' '; char two = '{';
        int n = s.length();
        unordered_map<char, int> mp;
        
        for(int i=0; i<n; i++){
            one = s[i];
            for(int j=i+1; j<n; j++){
                if(s[j] < one and mp.find(s[j]) == mp.end()){
                    two = min(s[j], two);
                }
            }
            
            if(two < one){
                break;
            }
            
            mp[one] = 1;
        }
        
        if(two == '{'){
            return s;
        }
        
        for(int i=0; i<n; i++){
            if(s[i] == one){
                s[i] = two;
            }
            else if(s[i] == two){
                s[i] = one;
            }
        }
        
        return s;
    }
    
};
