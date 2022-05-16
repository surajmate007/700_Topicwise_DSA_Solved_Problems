// using simple approach like unbounded knapsack problem:

class Solution{
	public:
	long long int count(int S[], int m, int n) {
		long long dp[m+1][n+1];
		for(int i=0; i<m+1; i++){
		    for(int j=0; j<n+1; j++){
			if(j==0){
			    dp[i][j] = 1;
			}
			else if(i==0){
			    dp[i][j] = 0;
			}
			else if(S[i-1] <= j){
			    dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j];
			}
			else{
			    dp[i][j] = dp[i-1][j];
			}
		    }
		}
        return dp[m][n];
    }
};
