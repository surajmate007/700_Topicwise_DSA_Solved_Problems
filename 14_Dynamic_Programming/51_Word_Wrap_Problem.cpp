// Using DP approach:

int solveWordWrap(vector<int>nums, int k){ 
       int n = nums.size();
       vector<vector<int>> dp(n,vector<int> (k+1,0));
       
       for(int i=0;i<=nums[n-1];i++){
           if(i>nums[n-1]){
               dp[n-1][i] = 0;
           }else{
               dp[n-1][i] =i*i ;
           }
       }
       
       for(int ind=n-2;ind>=0;ind--){
           for(int leftSpace=0;leftSpace<=k;leftSpace++){
               if(leftSpace > nums[ind]){
                   int y = (leftSpace == k)?
                   leftSpace-nums[ind]:(leftSpace-(nums[ind]+1));
                   dp[ind][leftSpace] =  min(
                               dp[ind+1][y],
                               (leftSpace*leftSpace) +dp[ind+1][k-nums[ind]]);  
               }
               else{
                   dp[ind][leftSpace] = (leftSpace*leftSpace) + dp[ind+1][k-nums[ind]];
               }
           }
       }
       return dp[0][k];   
   } 
};
