// Easy to understand recursive code:

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool getAns(unordered_map<string, int>& mp, string& s, int n, int idx, int last){
        if(idx > n){
            if(last == n) return 1;
            return 0;
        }
        
        string str = s.substr(last, idx-last);
        bool ans1 = 0; bool ans2 = 0;
        if(mp.find(str) != mp.end()){
            ans1 = getAns(mp, s, n, idx+1, idx);
            if(ans1) return ans1;
        }
        ans2 = getAns(mp, s, n, idx+1, last);
        if(ans2) return ans2;
        
        return 0;
    }
    
    int wordBreak(int n, string s, vector<string> &dictionary) {
        unordered_map<string, int> mp;
        for(auto e : dictionary) mp[e]++;
        int m = s.length();
        int ans = getAns(mp, s, m, 0, 0);
        return ans;
    }
};


// another dp solution
class Solution{
public:
    
    int wordBreak(string s, vector<string> &B) {
        int n = s.length();
        int m = B.size();
        bool dp[n+1];
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                string word = B[j];
                if(i+word.length() <= n and s.substr(i, word.length()) == word){
                    dp[i] = dp[i+word.length()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};


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

// second approach is using LIS:

