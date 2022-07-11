// Recursive Code:

int getAns(vector<vector<int>>& arr, int n, int i, int j){
    if(i == n){
        return 0;
    }
    
    int ans = arr[i][j];
    
    int temp = max(getAns(arr, n, i+1, (j+1)%3), getAns(arr, n, i+1, (j+2)%3)); 
 
    ans += temp;
    
    return ans;
}


int ninjaTraining(int n, vector<vector<int>> &points){
    int ans = 0;
    
    for(int j=0; j<3; j++){
        ans = max(ans, getAns(points, n, 0, j));
    }
    
    return ans;
}


// Memoised Version of Code:


#include<bits/stdc++.h>

int getAns(vector<vector<int>>& arr, int n, int i, int j, vector<vector<int>>& dp){
    if(i == n){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int ans = arr[i][j];
    
    int temp = max(getAns(arr, n, i+1, (j+1)%3, dp), getAns(arr, n, i+1, (j+2)%3, dp)); 
 
    ans += temp;
    
    return dp[i][j] = ans;
}


int ninjaTraining(int n, vector<vector<int>> &points){
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(3, -1));
    
    for(int j=0; j<3; j++){
        ans = max(ans, getAns(points, n, 0, j, dp));
    }
    
    return ans;
}


// Tabulation:

#include<bits/stdc++.h>

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(3, 0));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            if(i==0){
                dp[i][j] = points[i][j];
            }
            else{
                dp[i][j] = points[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}
