// This solution is written by using dp:
// This is problem of the day on 7 July 2022.

class Solution{
  public:
    
    bool getAns(string s1, int i, string s2, int j, string s3, int k, vector<vector<int>>& dp){
        if(i == s1.length()){
            return s2.substr(j) == s3.substr(k);
        }
        
        else if(j == s2.length()){
            return s1.substr(i) == s3.substr(k);
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        bool ans = false;
        if(s1[i]==s3[k] and s2[j]==s3[k]){
            ans = getAns(s1, i+1, s2, j, s3, k+1, dp) or getAns(s1, i, s2, j+1, s3, k+1, dp);
        }
        else{
            if(s1[i]==s3[k]){
                ans = getAns(s1, i+1, s2, j, s3, k+1, dp);
            }
            else if(s2[j]==s3[k]){
                ans = getAns(s1, i, s2, j+1, s3, k+1, dp);
            }
        }
        
        return dp[i][j] = ans;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(); int n2 = s2.length(); int n3 = s3.length();
        if(n1 + n2 != n3){
            return false;
        }
        
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return getAns(s1, 0, s2, 0, s3, 0, dp);
    }
};
