// Recursive Code:


class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int idx, int buy){
        if(idx == n){
            return 0;
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, idx+1, 0);
            int ans2 = getAns(prices, n, idx+1, 1);
            ans = max(ans1, ans2);
        }
        
        else{
            int ans1 = prices[idx] + getAns(prices, n, idx+1, 1);
            int ans2 = getAns(prices, n, idx+1, 0);
            ans = max(ans1, ans2);
        }
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = getAns(prices, n, 0, 1);
        
        return ans;
    }
};



// Memoised:


class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int idx, int buy, vector<vector<int>>& dp){
        if(idx == n){
            return 0;
        }
        
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, idx+1, 0, dp);
            int ans2 = getAns(prices, n, idx+1, 1, dp);
            ans = max(ans1, ans2);
        }
        
        else{
            int ans1 = prices[idx] + getAns(prices, n, idx+1, 1, dp);
            int ans2 = getAns(prices, n, idx+1, 0, dp);
            ans = max(ans1, ans2);
        }
        
        return dp[idx][buy] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        
        int ans = getAns(prices, n, 0, 1, dp);
        
        return ans;
    }
};
