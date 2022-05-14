// using simple top down approach 

class Solution{
	public:
	int minimumCost(int cost[], int N, int W) { 
        long long dp[N+1][W+1];
        for(int i=0; i<=N; i++){
            for(int j=0; j<=W; j++){
                if(i==0){
                    dp[i][j] = INT_MAX;
                }
                else if(j==0){
                    dp[i][j] = 0;
                }
                else if(cost[i-1] == -1){
                    dp[i][j] = dp[i-1][j];
                }
                else if(i <= j){
                    dp[i][j] = min(cost[i-1]+dp[i][j-i], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W]==INT_MAX ? -1:dp[N][W];
	} 
};
