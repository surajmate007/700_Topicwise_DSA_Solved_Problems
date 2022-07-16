// Recursion:


class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int idx, int buy, int trns){
        if(trns == 2 or idx == n){
            return 0;
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, idx+1, 0, trns);
            int ans2 = getAns(prices, n, idx+1, 1, trns);
            ans = max(ans1, ans2);
        }
        else{
            int ans1 = prices[idx] + getAns(prices, n, idx+1, 1, trns+1);
            int ans2 = getAns(prices, n, idx+1, 0, trns);
            ans = max(ans1, ans2);
        }
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
   
        return getAns(prices, n, 0, 1, 0);
    }
};


// Memoisation:



class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int idx, int buy, int trns, vector<vector<vector<int>>>& dp){
        if(trns == 2 or idx == n){
            return 0;
        }
        
        if(dp[idx][buy][trns] != -1){
            return dp[idx][buy][trns];
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, idx+1, 0, trns, dp);
            int ans2 = getAns(prices, n, idx+1, 1, trns, dp);
            ans = max(ans1, ans2);
        }
        else{
            int ans1 = prices[idx] + getAns(prices, n, idx+1, 1, trns+1, dp);
            int ans2 = getAns(prices, n, idx+1, 0, trns, dp);
            ans = max(ans1, ans2);
        }
        
        return dp[idx][buy][trns] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
        
        return getAns(prices, n, 0, 1, 0, dp);
    }
};



// Tabulation:

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        for(int i=0; i<prices.size(); i++){
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i]-buy1);
            
            buy2 = min(buy2, prices[i]-profit1);
            profit2 = max(profit2, prices[i]-buy2);
        }
        
        return profit2;
    }
};
