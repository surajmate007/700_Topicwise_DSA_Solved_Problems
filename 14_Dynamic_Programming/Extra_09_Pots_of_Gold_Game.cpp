// GFG:
// This is important type of DP where we have to find the optimal answer for 2 different players:
// Memoised Version:

class Solution {
public:
    
    int getAns(vector<int>& arr, int i, int j, int turn, vector<vector<vector<int>>>& dp){
        if(i > j){
            return 0;
        }
        
        if(dp[i][j][turn] != -1){
            return dp[i][j][turn];
        }
        
        int my = 0; int his = 0;
        
        if(turn == 1){
            int ans1 = arr[i] + getAns(arr, i+1, j, 1-turn, dp);
            int ans2 = arr[j] + getAns(arr, i, j-1, 1-turn, dp);
            my = max(ans1, ans2);
        }
        
        else{
            int ans1 = getAns(arr, i+1, j, 1-turn, dp);
            int ans2 = getAns(arr, i, j-1, 1-turn, dp);
            his = min(ans1, ans2);
        }
        
        return dp[i][j][turn] = max(my, his);
    }

    int maxCoins(vector<int>&arr, int n){
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
	    return getAns(arr, 0, n-1, 1, dp);
    }
};


// Leetcode 486: Similar problem:

class Solution {
public:
    
    int getAns(vector<int>& nums, int i, int j, int turn, vector<vector<vector<int>>>& dp){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j][turn] != -1){
            return dp[i][j][turn];
        }
        
        int my = 0; int his = 0;
        
        if(turn == 1){
            int ans1 = nums[i] + getAns(nums, i+1, j, 1-turn, dp);
            int ans2 = nums[j] + getAns(nums, i, j-1, 1-turn, dp);
            my = max(ans1, ans2);
        }
        else{
            int ans1 = getAns(nums, i+1, j, 1-turn, dp);
            int ans2 = getAns(nums, i, j-1, 1-turn, dp);
            his = min(ans1, ans2);
        }
        
        return dp[i][j][turn] = max(my, his);
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        long long total = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
        int score = getAns(nums, 0, n-1, 1, dp);
        if(total - score <= score){
            return true;
        }
        return false;
    }
};
