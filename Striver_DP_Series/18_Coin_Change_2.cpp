// Recursion:

class Solution {
public:
    
    int getAns(vector<int>& coins, int n, int idx, int tar){
        
        if(idx == n){
            if(tar == 0){
                return 1;
            }
            return 0;
        }
        
        int ans1 = 0; int ans2 = 0;
        
        if(coins[idx] <= tar){
            ans1 = getAns(coins, n, idx, tar-coins[idx]);
        }
        
        ans2 = getAns(coins, n, idx+1, tar);
        
        return ans1 + ans2;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return getAns(coins, n, 0, amount);
    }
};


// Memoisation:


class Solution {
public:
    
    int getAns(vector<int>& coins, int n, int idx, int tar, vector<vector<int>>& dp){
        
        if(idx == n){
            if(tar == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][tar] != -1){
            return dp[idx][tar];
        }
        
        int ans1 = 0; int ans2 = 0;
        
        if(coins[idx] <= tar){
            ans1 = getAns(coins, n, idx, tar-coins[idx], dp);
        }
        
        ans2 = getAns(coins, n, idx+1, tar, dp);
        
        return dp[idx][tar] = ans1 + ans2;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
        return getAns(coins, n, 0, amount, dp);
    }
};
