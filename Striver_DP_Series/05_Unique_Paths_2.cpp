// using recursion:

#include<bits/stdc++.h>
int mod = 1e9+7;

int getAns(vector<vector<int>> &mat, int n, int m, int i, int j){
    if(i>=n or j>=m){
        return 0;
    }
    
    if(mat[i][j] == -1){
        return 0;
    }
    
    if(i==n-1 and j==m-1){
        return 1;
    }
    
    int ans = 0;
    
    ans = (ans%mod + getAns(mat, n, m, i+1, j)%mod)%mod;
    ans = (ans%mod + getAns(mat, n, m, i, j+1)%mod)%mod;
    
    return ans%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    return getAns(mat, n, m, 0, 0);
}


// Using Memoisation:


#include<bits/stdc++.h>
int mod = 1e9+7;

int getAns(vector<vector<int>> &mat, int n, int m, int i, int j, vector<vector<int>>& dp){
    if(i>=n or j>=m){
        return 0;
    }
    
    if(mat[i][j] == -1){
        return 0;
    }
    
    if(i==n-1 and j==m-1){
        return 1;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j]%mod;
    }
    
    int ans = 0;
    
    ans = (ans%mod + getAns(mat, n, m, i+1, j, dp)%mod)%mod;
    ans = (ans%mod + getAns(mat, n, m, i, j+1, dp)%mod)%mod;
    
    return dp[i][j] = ans%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return getAns(mat, n, m, 0, 0, dp);
}


// Tabulation:


#include<bits/stdc++.h>
int mod = 1e9+7;

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    
    for(int i=1; i<n; i++){
        if(mat[i][0] == -1){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = dp[i-1][0];
        }
    }
    
    for(int j=1; j<m; j++){
        if(mat[0][j] == -1){
            dp[0][j] = 0;
        }
        else{
            dp[0][j] = dp[0][j-1];
        }
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
        }
    }
    return dp[n-1][m-1];
}
