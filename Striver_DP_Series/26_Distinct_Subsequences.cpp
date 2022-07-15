// Recursive Code:


class Solution {
public:
    
    int getAns(string& s1, string& s2, int n, int m, int idx1, int idx2){
        if(idx2 >= m){
            return 1;
        }
        
        if(idx1 >= n){
            return 0;
        }
        
        int ans = 0;
        
        if(s1[idx1] == s2[idx2]){
            ans = getAns(s1, s2, n, m, idx1+1, idx2+1) + getAns(s1, s2, n, m, idx1+1, idx2);
        }
        else{
            ans = getAns(s1, s2, n, m, idx1+1, idx2);
        }
        
        return ans;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(); int m = t.length();
        return getAns(s, t, n, m, 0, 0);
    }
};


// Memoised:


class Solution {
public:
    
    int getAns(string& s1, string& s2, int n, int m, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx2 >= m){
            return 1;
        }
        
        if(idx1 >= n){
            return 0;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        int ans = 0;
        
        if(s1[idx1] == s2[idx2]){
            ans = getAns(s1, s2, n, m, idx1+1, idx2+1, dp) + getAns(s1, s2, n, m, idx1+1, idx2, dp);
        }
        else{
            ans = getAns(s1, s2, n, m, idx1+1, idx2, dp);
        }
        
        return dp[idx1][idx2] = ans;
    }
    
    int numDistinct(string s, string t) {
        int n = s.length(); int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return getAns(s, t, n, m, 0, 0, dp);
    }
};
