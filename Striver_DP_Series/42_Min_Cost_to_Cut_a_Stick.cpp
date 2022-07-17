// Recursion:


class Solution {
public:
    
    int getAns(vector<int>& cuts, int n, int lo, int hi){
        if(lo==hi){
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int k=0; k<n; k++){
            if(cuts[k]>lo and cuts[k] < hi){
                int temp = getAns(cuts, n, lo, cuts[k]) + getAns(cuts, n, cuts[k], hi) +  (hi-lo);
                ans = min(ans, temp);
            }
        }
        
        if(ans == INT_MAX){
            return 0;
        }
        
        return ans;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        return getAns(cuts, m, 0, n);
    }
};



// Memoisation: (Also giving TLE)



class Solution {
public:
    
    int getAns(vector<int>& cuts, int lo, int hi, vector<vector<int>>& dp){
        if(lo > hi){
            return 0;
        }
        
        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }
        
        int ans = INT_MAX;
        
        for(int k=lo; k<=hi; k++){
            int temp = getAns(cuts, lo, k-1, dp) + getAns(cuts, k+1, hi, dp) + cuts[hi+1] - cuts[lo-1];
            ans = min(ans, temp);
        }
        
        return dp[lo][hi] = ans;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        return getAns(cuts, 1, m, dp);
    }
};



