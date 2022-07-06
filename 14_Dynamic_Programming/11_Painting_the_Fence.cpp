// simple solution using dp.
// for n=1 we can color with max k colours. when n=2 we can color with k*k colors.
// now when n=3 then we can color the last 2 blocks by k*k colors but the 3rd block will be coloured by different coor where we will have (k-1) different
// colours remaining. also we will consider the case when the 3rd block will be treated as individual block so we are adding dp[n-2] into the result.

class Solution{
    public:
    long long countWays(int n, int k)
    {
        long long int  mod = 1e9+7;
        long long int dp[n+1];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = k*k;
        for(long int i=3;i<=n;i++)
        {
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;
        }
        return dp[n];
    }
};
