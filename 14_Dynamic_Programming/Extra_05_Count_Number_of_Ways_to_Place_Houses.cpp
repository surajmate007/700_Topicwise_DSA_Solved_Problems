// Such type of problems uses fibonacci series.
// problem link : https://leetcode.com/contest/weekly-contest-299/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
     
    int countHousePlacements(int n) {
        long long mod = 1e9+7;
        int dp[n+1];
        dp[0] = 1; dp[1]=2;
        
        for(int i=2; i<=n; i++){
            dp[i] = ((dp[i-1])%mod + (dp[i-2])%mod)%mod;
        }
        
        int ans = (dp[n]%mod*dp[n]%mod)%mod;
        
        return ans;
    }
};
