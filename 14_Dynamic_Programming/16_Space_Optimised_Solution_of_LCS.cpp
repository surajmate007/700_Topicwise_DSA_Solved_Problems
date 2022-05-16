// One important observation in the normal simple implementation is, in each iteration of the outer loop we only need values from all
// columns of the previous row. So there is no need to store all rows in our DP matrix, we can just store two rows at a time and use them.
// In that way, used space will be reduced from L[m+1][n+1] to L[2][n+1]. Below is the implementation of the above idea.

class Solution{
    public:
    int lcs(int x, int y, string s1, string s2){
        int dp[2][y+1];
        bool bi;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                bi = i & 1;             // bi represents binary variable.
                if(i==0 or j==0){
                    dp[bi][j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[bi][j] = 1 + dp[1-bi][j-1];
                } 
                else{
                    dp[bi][j] = max(dp[1-bi][j], dp[bi][j-1]);
                }
            }
        }
        
        return dp[bi][y];
    }
};
