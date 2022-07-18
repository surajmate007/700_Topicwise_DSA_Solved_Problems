// Recursive:


class Solution {
public:
    
    int getAns(vector<int>& arr, int n, int p, int start){
        if(start == n){
            return 0;
        }
        
        int ans = 0;
        int mxf = 0;

        for(int k=start; k<min(n, start+p); k++){
            mxf = max(mxf, arr[k]);
            int temp = getAns(arr, n, p, k+1) + (k+1-start) * mxf;
            ans = max(ans, temp);
        }
        
        return ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return getAns(arr, n, k, 0);
    }
};



// Memoisation:


class Solution {
public:
    
    int getAns(vector<int>& arr, int n, int p, int start, vector<int>& dp){
        if(start == n){
            return 0;
        }
        
        if(dp[start] != -1){
            return dp[start];
        }
        
        int ans = 0;
        int mxf = 0;

        for(int k=start; k<min(n, start+p); k++){
            mxf = max(mxf, arr[k]);
            int temp = getAns(arr, n, p, k+1, dp) + (k+1-start) * mxf;
            ans = max(ans, temp);
        }
        
        return dp[start] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return getAns(arr, n, k, 0, dp);
    }
};



// Tabulation:


class Solution {
public:
    
    int maxSumAfterPartitioning(vector<int>& arr, int p) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        
        for(int start=n-1; start>=0; start--){
            int ans = 0; int mxf = 0;
            for(int k=start; k<min(n, start+p); k++){
                mxf = max(mxf, arr[k]);
                int temp = dp[k+1] + (k+1-start) * mxf;
                ans = max(ans, temp);
            }
            dp[start] = ans;
        }
        
        return dp[0];
    }
};
