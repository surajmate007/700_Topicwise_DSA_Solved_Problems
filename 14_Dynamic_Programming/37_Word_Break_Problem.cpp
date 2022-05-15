// good solution from youtube video.

class Solution{
public:
    
    int wordBreak(string s, vector<string> &B) {
        int n = s.length();
        int m = B.size();
        bool dp[n+1];
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                string word = B[i];
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
