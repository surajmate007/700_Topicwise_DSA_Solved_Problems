// Recursive Code:

int getAns(vector<int>& arr, int n, int idx, int sum1, int sum2){
    if(idx == n){
        return abs(sum1 - sum2);
    }
    
    int ans1 = getAns(arr, n, idx+1, sum1+arr[idx], sum2);
    int ans2 = getAns(arr, n, idx+1, sum1, sum2+arr[idx]);
    
    return min(ans1, ans2);
}

int minSubsetSumDifference(vector<int>& arr, int n){
	return getAns(arr, n, 0, 0, 0);
}



// memoised:


#include<bits/stdc++.h>

int getAns(vector<int>& arr, int n, int idx, int sum1, int sum2, vector<vector<int>>& dp){
    if(idx == n){
        return abs(sum1 - sum2);
    }
    
    if(dp[idx][sum1] != -1){
        return dp[idx][sum1];
    }
    
    int ans1 = getAns(arr, n, idx+1, sum1+arr[idx], sum2, dp);
    int ans2 = getAns(arr, n, idx+1, sum1, sum2+arr[idx], dp);
    
    return dp[idx][sum1] = min(ans1, ans2);
}

int minSubsetSumDifference(vector<int>& arr, int n){
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
	return getAns(arr, n, 0, 0, 0, dp);
}

