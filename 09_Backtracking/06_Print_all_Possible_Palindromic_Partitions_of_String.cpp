// Imporved solution by passing ds by reference.

class Solution {
public:
    
    bool isPalindrome(string s, int n){
        int i=0; int j=n-1;
        while(i< j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    void getAns(string s, int n, vector<string>& ds, vector<vector<string>>& ans){
        if(n==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++){
            string ns = s.substr(0, i+1);
            if(isPalindrome(ns, i+1)){
                ds.push_back(ns);
                getAns(s.substr(i+1), n-(i+1), ds, ans);
                ds.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>> ans;
        int n = s.length();
        
        getAns(s, n, ds, ans);
        
        return ans;
    }
};





// Code written by me.

class Solution {
  public:
    
    bool isPalindrome(string s, int n){
        int  i=0; int j = n-1;
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    void getAns(string s, int n, vector<string> ds, vector<vector<string>>& ans){
        if(s.size() == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0; i<n; i++){
            string ns = s.substr(0, i+1);
            if(isPalindrome(ns, i+1)){
                
                if(i+1 > 1){                            // Not understanding why I have to write this line.
                    ds.pop_back();
                }
                
                ds.push_back(ns);
                getAns(s.substr(i+1), n-(i+1), ds, ans);
            }
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        int n = s.length();
        getAns(s, n, ds, ans);
        
        return ans;
    }
};
