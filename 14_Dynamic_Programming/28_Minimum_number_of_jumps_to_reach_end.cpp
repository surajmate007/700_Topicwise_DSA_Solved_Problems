// using simple approach learned in array section.

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n==1){
            return 0;
        }
        else if(arr[0] == 0){
            return -1;
        }
        else{
            int maxR = arr[0]; int step = arr[0]; int jumps = 1;
            for(int i=1; i<n; i++){
                if(i == n-1){
                    return jumps;
                }
                maxR = max(maxR, i+arr[i]);
                step--;
                if(step == 0){
                    jumps++;
                    if(i >= maxR){
                        return -1;
                    }
                    step += maxR-i;
                }
            }
        }
        
    }
};

// code using DP but giving TLE:

class Solution{
  public:
    int minJumps(int arr[], int n){
        int dp[n+1];
        for(int i=0; i<n; i++){
            dp[i] = INT_MAX;
        }

        if(n==1){
            return 0;
        }
        
        if(arr[0] == 0){
            return -1;
        }
        
        dp[0] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(i <= j+arr[j]){
                    dp[i] = min(dp[i], 1+dp[j]);
                }
            }
            if(dp[i] == INT_MAX){
                return -1;
            }
        }
        
        return dp[n-1];
    }
};
