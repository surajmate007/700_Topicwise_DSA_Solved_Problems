// Easy approach:

class Solution {
public:
    
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<long long> dp(26, 0);
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            int idx = s[i]-'a';
            dp[idx] = dp[idx]+1;
            
            for(int j=max(0, idx-k); j<=min(25, idx+k); j++){
                if(idx!=j){
                    dp[idx] = max(dp[idx], dp[j]+1);
                }
                ans = max(ans, dp[idx]);
            }
        }
        
        return ans;
    }
};
