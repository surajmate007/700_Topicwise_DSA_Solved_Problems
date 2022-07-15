// Recursive:


class Solution {
public:
    
    int getAns(string& s1, string& s2, int n, int m, int idx1, int idx2){
        if(idx1 >= n){
            return m-idx2;
        }
        
        if(idx2 >= m){
            return n-idx1;
        }
        
        int ans = 0;
        
        if(s1[idx1] == s2[idx2]){
            ans = getAns(s1, s2, n, m, idx1+1, idx2+1);
        }
        else{
            int ans1 = 1 + getAns(s1, s2, n, m, idx1+1, idx2);
            int ans2 = 1 + getAns(s1, s2, n, m, idx1+1, idx2+1);
            int ans3 = 1 + getAns(s1, s2, n, m, idx1, idx2+1);
            
            ans = min({ans1, ans2, ans3});
        }
        
        return ans;
    }
    
    int minDistance(string s1, string s2) {
        int n = s1.length(); int m = s2.length();
        
        return getAns(s1, s2, n, m, 0, 0);
    }
};


// Memoised:


class Solution {
public:
    
    int getAns(string& s1, string& s2, int n, int m, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n){
            return m-idx2;
        }
        
        if(idx2 >= m){
            return n-idx1;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        int ans = 0;
        
        if(s1[idx1] == s2[idx2]){
            ans = getAns(s1, s2, n, m, idx1+1, idx2+1, dp);
        }
        else{
            int ans1 = 1 + getAns(s1, s2, n, m, idx1+1, idx2, dp);
            int ans2 = 1 + getAns(s1, s2, n, m, idx1+1, idx2+1, dp);
            int ans3 = 1 + getAns(s1, s2, n, m, idx1, idx2+1, dp);
            
            ans = min({ans1, ans2, ans3});
        }
        
        return dp[idx1][idx2] = ans;
    }
    
    int minDistance(string s1, string s2) {
        int n = s1.length(); int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return getAns(s1, s2, n, m, 0, 0, dp);
    }
};
