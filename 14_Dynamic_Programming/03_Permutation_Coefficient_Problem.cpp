// we are simply implementing the formula relation::      nPr = (n-1)Pr + r * (n-1)P(r-1)

class Solution{
public:
    const long long mod = 1e9 + 7;
    int memo[1001][1001];
    
    int nPr(int n, int r){
        if (n < r) return 0;

        for (int j = 0;j < r + 1;j++) {
            memo[0][j] = 0;
        }
        for (int i = 0;i < n + 1;i++) {
            memo[i][0] = 1;
        }
    
        for (int i = 1;i < n + 1;i++) {
            for (int j = 1;j <= min(i, r);j++) {
                memo[i][j] = (memo[i - 1][j] % mod + (j * memo[i - 1][j] % mod)) % mod;
            }
        }
        return memo[n][r] % mod;
    }
};
