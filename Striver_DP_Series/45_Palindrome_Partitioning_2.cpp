// Recursive Code:


class Solution {
public:
    
    bool isPalin(string s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    
    int getAns(string s, int lo, int hi){
        if(lo >= hi){
            return 0;
        }
        
        if(isPalin(s, lo, hi)){
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int k=lo; k<hi; k++){
            int temp = getAns(s, lo, k) + getAns(s, k+1, hi) + 1;
            ans = min(ans, temp);
        }
        
        return ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        return getAns(s, 0, n-1);
    }
};



// Memoised (Giving TLE):


class Solution {
public:
    
    bool isPalin(string s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    
    int getAns(string s, int lo, int hi, vector<vector<int>>& dp){
        if(lo >= hi){
            return 0;
        }
        
        if(isPalin(s, lo, hi)){
            return 0;
        }
        
        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
        
        int ans = INT_MAX;
        
        for(int k=lo; k<hi; k++){
            int temp = getAns(s, lo, k, dp) + getAns(s, k+1, hi, dp) + 1;
            ans = min(ans, temp);
        }
        
        return dp[lo][hi] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return getAns(s, 0, n-1, dp);
    }
};



// Tabulation (Giving TLE):


int minCut(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int lo=n-1; lo>=0; lo--){
            for(int hi=lo+1; hi<n; hi++){
                if(isPalin(s, lo, hi)){
                    dp[lo][hi] = 0;
                }
                else{
                    int ans = INT_MAX;
                    for(int k=lo; k<hi; k++){
                        int temp = dp[lo][k] + dp[k+1][hi] + 1;
                        ans = min(ans, temp);
                    }
                    dp[lo][hi] = ans;
                }
            }
        }        
        return dp[0][n-1];
    }





// Modified Recursion:
// Using concept of front partitioning.


class Solution {
public:
    
    bool isPalin(string s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    
    int getAns(string s, int n, int start){
        if(start == n){
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int i=start; i<n; i++){
            if(isPalin(s, start, i)){
                int temp = 1 + getAns(s, n, i+1);
                ans = min(ans, temp);
            }
        }
        
        return ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        return getAns(s, n, 0)-1;
    }
};



// Memoisation:



class Solution {
public:
    
    bool isPalin(string s, int i, int j){
        while(i < j){
            if(s[i] == s[j]){
                i++; j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    
    int getAns(string s, int n, int start, vector<int>& dp){
        if(start == n){
            return 0;
        }
        
        if(dp[start] != -1){
            return dp[start];
        }
        
        int ans = INT_MAX;
        
        for(int i=start; i<n; i++){
            if(isPalin(s, start, i)){
                int temp = 1 + getAns(s, n, i+1, dp);
                ans = min(ans, temp);
            }
        }
        
        return dp[start] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        return getAns(s, n, 0, dp)-1;
    }
};




// Tabulation:




