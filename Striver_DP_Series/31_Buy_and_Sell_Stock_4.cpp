// Recursion:


class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int trns, int idx, int buy){
        if(idx>=n or trns==0){
            return 0;
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, trns, idx+1, 0);
            int ans2 = getAns(prices, n, trns, idx+1, 1);
            ans = max(ans1, ans2);
        }
        
        else{
            int ans1 = prices[idx] + getAns(prices, n, trns-1, idx+1, 1);
            int ans2 = getAns(prices, n, trns, idx+1, 0);
            ans = max(ans1, ans2);
        }
        
        return ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return getAns(prices, n, k, 0, 1); 
    }
};


// Memoisation:



class Solution {
public:
    
    int getAns(vector<int>& prices, int n, int trns, int idx, int buy, vector<vector<vector<int>>>& dp){
        if(idx>=n or trns==0){
            return 0;
        }
        
        if(dp[idx][buy][trns] != -1){
            return dp[idx][buy][trns];
        }
        
        int ans = 0;
        
        if(buy == 1){
            int ans1 = -prices[idx] + getAns(prices, n, trns, idx+1, 0, dp);
            int ans2 = getAns(prices, n, trns, idx+1, 1, dp);
            ans = max(ans1, ans2);
        }
        
        else{
            int ans1 = prices[idx] + getAns(prices, n, trns-1, idx+1, 1, dp);
            int ans2 = getAns(prices, n, trns, idx+1, 0, dp);
            ans = max(ans1, ans2);
        }
        
        return dp[idx][buy][trns] = ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2, vector<int> (k+1, -1)));
        return getAns(prices, n, k, 0, 1, dp); 
    }
};
