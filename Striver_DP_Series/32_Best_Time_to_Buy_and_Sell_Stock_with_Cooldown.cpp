// Recursion:


class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int buy, int idx){
        if(idx >= n){
            return 0;
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, 0, idx+1);
            int ans2 = getAns(prices, n, 1, idx+1);
            ans = max(ans1, ans2);
        }
        else{
            int ans1 = prices[idx] + getAns(prices, n, 1, idx+2);
            int ans2 = getAns(prices, n, 0, idx+1);
            ans = max(ans1, ans2);
        }
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return getAns(prices, n, 1, 0);
    }
};


// Memoisation:



class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int buy, int idx, vector<vector<int>>& dp){
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, 0, idx+1, dp);
            int ans2 = getAns(prices, n, 1, idx+1, dp);
            ans = max(ans1, ans2);
        }
        else{
            int ans1 = prices[idx] + getAns(prices, n, 1, idx+2, dp);
            int ans2 = getAns(prices, n, 0, idx+1, dp);
            ans = max(ans1, ans2);
        }
        
        return dp[idx][buy] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        
        return getAns(prices, n, 1, 0, dp);
    }
};
