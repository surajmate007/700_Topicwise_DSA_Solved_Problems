// Recursion:

class Solution{
	public:
	
	int getAns(int cost[], int n, int idx, int w){
	    if(idx > n){
	        if(w==0){
	            return 0;
	        }
	        return 1e9;
	    }
	    
	    int ans = 0;
	    
	    if(idx <= w and cost[idx-1] != -1){
	        int ans1 = cost[idx-1] + getAns(cost, n, idx, w-idx);
	        int ans2 = getAns(cost, n, idx+1, w);
	        ans = min(ans1, ans2);
	    }
	    else{
	        ans = getAns(cost, n, idx+1, w);
	    }
	    
	    return ans;
	}
	
	int minimumCost(int cost[], int n, int w) { 
		int ans = getAns(cost, n, 1, w);

		if(ans == 1e9){
		    return -1;
		}
		return ans;
	} 
};


// Memoisation:

class Solution{
	public:
	
	int getAns(int cost[], int n, int idx, int w, vector<vector<int>>& dp){
	    if(idx > n){
	        if(w==0){
	            return 0;
	        }
	        return 1e9;
	    }
	    
	    if(dp[idx][w] != -1){
	        return dp[idx][w];
	    }
	    
	    int ans = 0;
	    
	    if(idx <= w and cost[idx-1] != -1){
	        int ans1 = cost[idx-1] + getAns(cost, n, idx, w-idx, dp);
	        int ans2 = getAns(cost, n, idx+1, w, dp);
	        ans = min(ans1, ans2);
	    }
	    else{
	        ans = getAns(cost, n, idx+1, w, dp);
	    }
	    
	    return dp[idx][w] = ans;
	}
	
	int minimumCost(int cost[], int n, int w) { 
	    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
        int ans = getAns(cost, n, 1, w, dp);
        
        if(ans == 1e9){
            return -1;
        }
        return ans;
	} 
};


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
