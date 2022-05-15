// we are simply implementing the formula relation::      nPr = (n-1)Pr + r * (n-1)P(r-1)

int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];
 
    // Calculate value of Permutation
    // Coefficient in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            // Base Cases
            if (j == 0)
                P[i][j] = 1;
            
            else
                P[i][j] = P[i - 1][j] + (j * P[i - 1][j - 1]);
 
            // This step is important
            // as P(i,j)=0 for j>i
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}


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
                memo[i][j] = (memo[i - 1][j] % mod + (j * memo[i - 1][j-1] % mod)) % mod;
            }
        }
        return memo[n][r] % mod;
    }
};
