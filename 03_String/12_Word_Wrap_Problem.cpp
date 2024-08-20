// Recursion + Memoisation

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[600][2010];
    long long getAns(vector<int>& nums, int idx, int n, int width, int k){
        if(idx >= n) return 0;
        if(dp[idx][k] != -1) return dp[idx][k];
        
        long long ans1 = INT_MAX; long long ans2 = INT_MAX;
        if(k != width) k--;
        if(k >= nums[idx]){
            int rem = k - nums[idx];
            long long take = (rem * rem) + getAns(nums, idx+1, n, width, width);
            long long notTake = getAns(nums, idx+1, n, width, rem);
            ans1 = min(take, notTake);
        }
        else{
            k++;
            ans2 =  (k * k) + getAns(nums, idx, n, width, width);
        }
        
        return dp[idx][k] = (ans1 < ans2) ? ans1 : ans2;
    }
    
    int solveWordWrap(vector<int>nums, int k) { 
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        long long ans = getAns(nums, 0, n, k, k);
        return ans;
    }
};



// Using DP approach Top Down

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
