// Recursion:


int getAns(vector<int>& arr, int n, int sum1, int sum2, int d, int idx){
    if(idx == n){
        if(sum1-sum2==d){
            return 1;
        }
        return 0;
    }
    
    int ans1 = getAns(arr, n, sum1+arr[idx], sum2, d, idx+1);
    int ans2 = getAns(arr, n, sum1, sum2+arr[idx], d, idx+1);
    
    return ans1 + ans2;
}

int countPartitions(int n, int d, vector<int> &arr) {
    return getAns(arr, n, 0, 0, d, 0);
}



// Memoisation:


#include<bits/stdc++.h>
int mod = 1e9+7;

int getAns(vector<int>& arr, int n, int sum1, int sum2, int d, int idx, vector<vector<int>>& dp){
    if(idx == n){
        if(sum1-sum2==d){
            return 1;
        }
        return 0;
    }
    
    if(dp[idx][sum1] != -1){
        return dp[idx][sum1];
    }
    
    int ans1 = getAns(arr, n, sum1+arr[idx], sum2, d, idx+1, dp);
    int ans2 = getAns(arr, n, sum1, sum2+arr[idx], d, idx+1, dp);
    
    return dp[idx][sum1] = (ans1%mod + ans2%mod)%mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    
    return getAns(arr, n, 0, 0, d, 0, dp)%mod;
}
