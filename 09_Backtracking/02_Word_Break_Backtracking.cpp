// Very easy and intuitive solution.

// I understood new concept from these problems. When we pass the parameter by value not by reference then we dont need to do pop_back when the
// function returns. Since it is passed by value hence a new copy will be created of ds for every new recursive call and thus when the function returns
// The original value is maintained there.

class Solution{
public:
    unordered_map<string,int> mp;
    
    void getWords(string s, int len, int i, string ds, vector<string>& ans){
        if(i==len){
            ds.pop_back();
            ans.push_back(ds);
            return;
        }
        
        for(int j=i; j<=len; j++){
            string st = s.substr(i, j-i);
            if(mp.find(st) != mp.end()){
                
                getWords(s, len, j, ds+st+" ", ans);  // When the function returns after return condition the ds value will reset to the original
                                                      // caller value and hence after return flow will go out of if statement and j value will increment. 
            
            }
        }
    }
        
    vector<string> wordBreak(int n, vector<string>& dict, string s){
        mp.clear();
        for(int i=0; i<dict.size(); i++){
            mp[dict[i]] = 1;
        }
        
        int len = s.length();
        string ds;
        vector<string> ans;
        getWords(s, len, 0, ds, ans);
        
        return ans;
    }
};


// another similar and good approach:


#include<bits/stdc++.h>
vector<string> ans;
unordered_set<string> st;

void getAns(string s, string& ds){
    if(s.length() == 0){
        ds.pop_back();
        ans.push_back(ds);
        return;
    }
    
    for(int i=0; i<s.length(); i++){
        string ns = s.substr(0, i+1);
        if(st.find(ns) != st.end()){
            int len = ds.length();
            ds += (ns + " ");
            getAns(s.substr(i+1), ds);
            ds = ds.substr(0, len);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary){
    ans.clear(); st.clear();
    for(int i=0; i<dictionary.size(); i++){
        st.insert(dictionary[i]);
    }
    string ds = "";
    getAns(s, ds);
    
    return ans;
}
