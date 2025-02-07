// good solution from youtube video.

#include<bits/stdc++.h>
unordered_set<string> st;

bool wordBreak(vector<string>& arr, int n, string& s) {
    st.clear();
    for(int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    
    int len = s.length();
    vector<bool> dp(len+1);
    dp[len] = true;
    
    for(int i=len-1; i>=0; i--){
        for(auto word : arr){
            int sz = word.length();
            if(i+sz<=len and st.find(s.substr(i, sz)) != st.end()){
                dp[i] = dp[i+sz];
                break;
            }
        }
    }
    
    return dp[0];
}


// another simple solution:

class Solution{
public:
    unordered_set<string>st;
    int dp[1101];
    
    int solve(string s, int idx){
        if(idx == s.length()){
            return 1;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        string sub;
        
        for(int j=idx; j<s.length(); j++){
            sub += s[j];
            if(st.find(sub) != st.end()){
                if(solve(s, j+1)==1){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    
    int wordBreak(string s, vector<string> &B) {
        for(int i=0; i<B.size(); i++){
            st.insert(B[i]);
        }
        memset(dp, -1, sizeof(dp));
        return solve(s, 0);
    }
};

// solution from reference github profile modification of longest increasing subsequence:

int wordBreak(string A, vector<string>& B) {
    set<string> s;
    for (string i : B) s.insert(i);


    int n = A.size();
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));  // to avoid garbage value.

    dp[0] = 1;  // empty string is always in dictionary.

    for (int i = 1;i < n + 1;i++) {
        for (int j = 0;j < i;j++) {
            /*
                here dp is of N+1 index based while string is of 0 based
                hence dp[0] means empty string while A.substr(0, len) is starting from pos=0.
                so everytime comparison will be like: str=abcd
                ("" && "abcd") ("a" && "bcd") ("ab" && "cd") ...
                to check every possibilities.
            */
            if (dp[j] && s.find(A.substr(j, i - j)) != s.end()) {
                // if prev substring's dp is true and new substring is also true then we will set 1 and break.
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}
