// This is simple soluion based on recursive calls.
// Here we can see that the height of left subtree can have height of h-1 and left subtree can have height of h-2. Similar case can be inverted where the 
// right subtree will have height of h-2 and right will have height of h-1 and both left and right subtree can have same height od h-1 and h-1.
// Thus total number of bbt possible = dp[i-2]*dp[i-1] + dp[i-2]*dp[i-1] + dp[i-1]*dp[i-1]


class Solution {
  public:
    long long int countBT(int h) { 
        long long int mod = 1e9+7;
        long long int dp[h+1];
        dp[0] = dp[1] = 1;
        
        for(int i=2; i<=h; i++){
            dp[i] = ((dp[i-1]%mod * ((2 * dp[i-2]%mod)%mod + dp[i-1]%mod)))%mod;
        }
        
        return dp[h]%mod;
    }
};
