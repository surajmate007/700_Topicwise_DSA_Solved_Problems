// recursive code

int countDistinctWayToClimbStair(long long n){
    
    if(n<0){
        return 0;
    }
    
    if(n==0){
        return 1;
    }
    
    else{
        return countDistinctWayToClimbStair(n-1) + countDistinctWayToClimbStair(n-2);
    }
}

// memoizatoion:

class Solution {
public:
    int getAns(int n, vector<int>& dp){
        if(n==0 or n==1){
            return 1;
        }
        
        else if(dp[n] != -1){
            return dp[n];
        }
        
        else{
            return dp[n] = getAns(n-1, dp) + getAns(n-2, dp); 
        }
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return getAns(n, dp);
    }
};
