// using dp approach
// https://www.youtube.com/watch?v=vlbA8oUxSV0        well explained in this video

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
