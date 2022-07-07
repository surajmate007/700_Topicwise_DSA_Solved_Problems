// solution using dp.


class Solution{
    public:
    long long dp[1001][1001];
    
    long long solve(int a[], int i, int j){
        if(i>j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int x = a[i] + min(solve(a, i+2, j), solve(a, i+1, j-1));   // we are choosing the first element of the arrya and the opponent is choosing the 
                                                                    // optimal element from the remaining element.
                                                                    // thus we are showing this using the min when opponent can choose the first or last element.
      
      
        int y = a[j] + min(solve(a, i+1, j-1), solve(a, i, j-2));   // similarly here we are chosimg the last element asd the opponent can choose from the rem array.
        
        return dp[i][j] = max(x, y);
    }
    
    long long maximumAmount(int arr[], int n){
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, 0, n-1);
    }
};
