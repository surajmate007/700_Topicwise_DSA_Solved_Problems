// This problem is alreadys solved in DP section:

long long int dp[1001][1001];
const long long int mod = 1e9+7;
    
    long long int lps(string str, int i, int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(str[i] == str[j]){
            int left, right;
            if(dp[i+1][j] != -1){
                left = dp[i+1][j];
            }
            else{
                left = lps(str, i+1, j);
            }
            if(dp[i][j-1] != -1){
                right = dp[i][j-1];
            }
            else{
                right = lps(str, i, j-1);
            }
            return dp[i][j] = (1 + left + right)%mod;
        }
        else{
            int left, right, mid;
            
            if(dp[i+1][j] != -1){
                left = dp[i+1][j];
            }
            else{
                left = lps(str, i+1, j);
            }
            if(dp[i][j-1] != -1){
                right = dp[i][j-1];
            }
            else{
                right = lps(str, i, j-1);
            }
            if(dp[i+1][j-1] != -1){
                mid = dp[i+1][j-1];
            }
            else{
                mid = lps(str, i+1, j-1);
            }
            
            return dp[i][j] = (mod + left + right - mid)%mod;
        }
    }
    
    long long int  countPS(string str){
       memset(dp, -1, sizeof(dp));
       int n = str.size()-1;
       return lps(str, 0, n);
    }



// GFG Solution:
// Function return the total palindromic subsequence
int countPS(string str){
    int N = str.length();
 
    // create a 2D array to store the count of palindromic
    // subsequence
    int cps[N + 1][N + 1];
    memset(cps, 0, sizeof(cps));
 
    // palindromic subsequence of length 1
    for (int i = 0; i < N; i++)
        cps[i][i] = 1;
 
    // check subsequence of length L is palindrome or not
    for (int L = 2; L <= N; L++) {
        for (int i = 0; i <= N-L; i++) {
            int k = L + i - 1;
            if (str[i] == str[k])
                cps[i][k]
                    = cps[i][k - 1] + cps[i + 1][k] + 1;
            else
                cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
                            - cps[i + 1][k - 1];
        }
    }
 
    // return total palindromic subsequence
    return cps[0][N - 1];
}
