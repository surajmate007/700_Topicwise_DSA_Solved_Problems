// Recursive Code:


#include<bits/stdc++.h>

int getAns(vector<int>& coins, int n, int tar, int idx){
    
    if(idx == n){
        if(tar == 0){
            return 0;
        }
        return 1e9;
    }
    
    int ans1 = 1e9; int ans2 = 1e9;
    if(coins[idx] <= tar){
        ans1 = 1 + getAns(coins, n, tar-coins[idx], idx);
    }
    
    ans2 = getAns(coins, n, tar, idx+1);
    
    return min(ans1, ans2);
}

int minimumCoins(int p){
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = coins.size();
    return getAns(coins, n, p, 0);
}


// Memoosed:



class Solution {
public:
    
    int getAns(vector<int>& coins, int n, int idx, int tar, vector<vector<int>>& dp){
        if(idx == n){
            if(tar == 0){
                return 0;
            }
            return 1e9;
        }
        
        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }
        
        int ans1 = 1e9; int ans2 = 1e9;
        if(coins[idx] <= tar){
            ans1 = 1 + getAns(coins, n, idx, tar-coins[idx], dp);
        }
        ans2 = getAns(coins, n, idx+1, tar, dp);
        
        return dp[idx][tar] = min(ans1, ans2);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        
        int ans = getAns(coins, n, 0, amount, dp);
        
        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};
