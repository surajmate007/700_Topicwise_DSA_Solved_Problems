// Non recursive solution for this problem:

class Solution{
    public:
    string removeConsecutiveCharacter(string s){
        int n = s.length(); string ans = "";
        for(int i=0; i<n; i++){
            char temp = s[i];
            if(ans.size() == 0 or ans.back() != temp){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

// Recursive solution for this problem:

class Solution{
    public:
    void removechar(string s, string& ans){
        if(s.size() == 0){
            return;
        }
        if(s[0] != ans.back()){
            ans.push_back(s[0]);
        }
        removechar(s.substr(1, s.size()-1), ans);
    }
    
    string removeConsecutiveCharacter(string s){
        string ans;
        removechar(s, ans);
        return ans;
    }
};
