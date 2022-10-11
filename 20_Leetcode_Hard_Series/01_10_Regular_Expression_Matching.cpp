// simple solution:
// handle all possible cases via recursion.

class Solution {
public:
    bool getAns(string& s, string& p, int n, int m, int i, int j, vector<vector<int>>& dp){
        if(j>=m and i>=n){
            return true;
        }
        if(j>=m){
            return false;
        }
        if(i>=n){
            if(p[j] == '*'){
                return getAns(s, p, n, m, i, j+1, dp);
            }
            else if(j+1<m and p[j+1]=='*'){
                return getAns(s, p, n, m, i, j+2, dp);
            }
            else{
                return false;
            }
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(j+1<m and p[j+1] == '*'){
            char ch = p[j];
            if(getAns(s, p, n, m, i, j+2, dp)){
                return true;
            }
            while(i<n and (s[i]==ch or ch=='.')){
                if(getAns(s, p, n, m, i+1, j+2, dp)){
                    return true;
                }
                i++;
            }
            return false;
        }
        else if(s[i] == p[j] or p[j]=='.'){
            return dp[i][j] = getAns(s, p, n, m, i+1, j+1, dp);
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(); int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return getAns(s, p, n, m, 0, 0, dp);
    }
};
