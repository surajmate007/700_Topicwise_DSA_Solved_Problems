// Recursion:


class Solution{
public:

    int getAns(int arr[], int lo, int hi){
        if(lo == hi){
            return 0;
        }
      
        int ans = INT_MAX;
        
        for(int k=lo; k<hi; k++){
            int temp = getAns(arr, lo, k) + getAns(arr, k+1, hi) + arr[lo-1] * arr[k] * arr[hi];
            ans = min(ans, temp);
        }
        
        return ans;
    }

    int matrixMultiplication(int N, int arr[]){
        return getAns(arr, 1, N-1);
    }
};


// Memoisation:



class Solution{
public:

    int getAns(int arr[], int lo, int hi, vector<vector<int>>& dp){
        if(lo == hi){
            return 0;
        }
        
        if(dp[lo][hi] != -1){
            return dp[lo][hi];
        }

        int ans = INT_MAX;
        
        for(int k=lo; k<hi; k++){
            int temp = getAns(arr, lo, k, dp) + getAns(arr, k+1, hi, dp) + arr[lo-1] * arr[k] * arr[hi];
            ans = min(ans, temp);
        }
        
        return dp[lo][hi] = ans;
    }

    int matrixMultiplication(int N, int arr[]){
        vector<vector<int>> dp(N+1, vector<int> (N+1, -1));
        return getAns(arr, 1, N-1, dp);
    }
};
