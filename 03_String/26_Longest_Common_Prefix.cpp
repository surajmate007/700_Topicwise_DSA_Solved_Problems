// we have 2 solution approaches:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = INT_MAX; int n = strs.size();
        string ans = "";
        for(int i=0; i<strs.size(); i++){
            int min = strs[i].length();
            if(min < size){
                size = min;
            }
        }
       for(int i=0; i<size; i++){
           for(int j=0; j<n; j++){
               if(strs[0][i] != strs[j][i]){return ans;}
           }
           ans += strs[0][i];
       }
        
        return ans;
    }
};

// second self written code:

class Solution {
public:
    
    int getprefix(string& ans, int n, string w){
        for(int i=0; i<n; i++){
            if(ans[i] != w[i]){
                ans = ans.substr(0, i);
                n = i;
            }
        }
        return n;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string ans = ""; int n = strs.size();
        if(n==1){
            return strs[0];
        }
        string w1 = strs[0]; string w2 = strs[1];
        for(int j=0; j<min(w1.size(), w2.size()); j++){
            if(w1[j] == w2[j]){
                ans += w1[j];
            }
            else{
                break;
            }
        }
        
        if(n==2 or ans==""){
            return ans;
        }
        
        int len = ans.size();
        for(int i=2; i<n; i++){
            len = getprefix(ans, len, strs[i]);
        }
        
        return ans;
    }
};
