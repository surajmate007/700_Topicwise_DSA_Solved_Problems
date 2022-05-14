// Solution is in topdown approach
// We can consider one item any number of times hence in 0-1 knapsack we used to reduce the array size by 1 after considering the element
// but here we will not reduce the array size since we can consider it multiple times.

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        int dp[N+1][W+1];
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else if(wt[i-1] <= j){
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
    }
};
