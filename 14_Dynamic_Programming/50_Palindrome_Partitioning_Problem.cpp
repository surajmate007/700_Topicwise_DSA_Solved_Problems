// solved in our handwritten notes. variation of MCM:
// Memoized approach but giving TLE.

class Solution{
public:
    int dp[1001][1001]; 
    
    bool isPalin(string s, int i, int j){
        while(i<j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int palincuts(string s, int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(isPalin(s, i, j) == true){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int mn = INT_MAX;
        for(int k=i; k<j; k++){
            int temp_ans = 1 + palincuts(s, i, k) + palincuts(s, k+1, j);
            mn = min(mn, temp_ans);
        }
        return dp[i][j] = mn;
    }
    
    int palindromicPartition(string str){
        memset(dp, -1, sizeof(dp));
        return palincuts(str, 0, str.size()-1);
    }
};

// More efficient code where before every recursive call we are first checking whether the dp entry corresponding to this call is filled or not.

class Solution{
public:
    int dp[1001][1001]; 
    
    bool isPalin(string s, int i, int j){
        while(i<j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    int palincuts(string s, int i, int j){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(isPalin(s, i, j) == true or i>=j){
            return dp[i][j] = 0;
        }
        
        int mn = INT_MAX; int left, right;
        for(int k=i; k<j; k++){
            if(dp[i][k] != -1){
                left = dp[i][k];
            }
            else{
                left = palincuts(s, i, k);
            }
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }
            else{
                right = palincuts(s, k+1, j);
            }
            int temp_ans = 1 + left + right;
            mn = min(mn, temp_ans);
        }
        return dp[i][j] = mn;
    }
    
    int palindromicPartition(string str){
        memset(dp, -1, sizeof(dp));
        return palincuts(str, 0, str.size()-1);
    }
};
