// Recursive code:


class Solution {
public:
    
    bool getAns(string& s, string& p, int n, int m, int idx1, int idx2){
        if(idx1 >= n and idx2 >= m){
            return true;
        }
        
        if(idx1 >= n or idx2 >= m){
            return false;
        }
        
        bool ans = false;
        
        if(s[idx1] == p[idx2] or p[idx2]=='?'){
            ans = getAns(s, p, n, m, idx1+1, idx2+1);
        }
        
        else if(p[idx2]=='*'){
            int i = idx1;
            while(i<=n){
                ans = ans or getAns(s, p, n, m, i, idx2+1);
                i++;
            }
            ans = ans or getAns(s, p, n, m, i, idx2+1);
        }
        
        return ans;
    }
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        return getAns(s, p, n, m, 0, 0);
    }
};



// memoised:


class Solution {
public:
    
    bool getAns(string& s, string& p, int n, int m, int idx1, int idx2, vector<vector<int>>& dp){
        if(idx1 >= n and idx2 >= m){
            return true;
        }
        
        if(idx1 >= n){
            while(p[idx2] == '*'){
                idx2++;
            }
            if(idx2 >= m){
                return true;
            }
            return false;
        }
        
        if(idx2 >= m){
            return false;
        }
        
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        
        bool ans = false;
        
        if(s[idx1] == p[idx2] or p[idx2]=='?'){
            ans = getAns(s, p, n, m, idx1+1, idx2+1, dp);
        }
        
        else if(p[idx2]=='*'){
            int i = idx1;
            while(i<=n){
                ans = ans or getAns(s, p, n, m, i, idx2+1, dp);
                
                if(ans == true){
                    return true;
                }
                
                i++;
            }
        }
        return dp[idx1][idx2] = ans;
    }
    
    
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        if(m==0){
            if(n==0){
                return true;
            }
            else{
                return false;
            }
        }

        if(n==0){
            for(int i=0; i<m; i++){
                if(p[i] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        return getAns(s, p, n, m, 0, 0, dp);
    }
};

