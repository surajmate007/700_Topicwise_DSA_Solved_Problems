// very elegent solution

int AlternatingaMaxLength(vector<int>&nums){
		    int ans1=1,ans2=1;
            for(int i=1;i<nums.size();i++){
              if(nums[i]>nums[i-1]){
                 ans1=ans2+1;
              }
              else if(nums[i]<nums[i-1]){
                ans2=ans1+1;
              }
          }
          return max(ans1,ans2);
}

// using DP approach:

int AlternatingaMaxLength(vector<int>&nums){
		    int n = nums.size();
		    int dp[2][n];
		    dp[0][0] = 1; dp[1][0] = 1;
		    for(int i=1; i<n; i++){
		        if(nums[i] > nums[i-1]){
		            dp[0][i] = dp[1][i-1]+1;
		            dp[1][i] = dp[1][i-1];
		        }
		        else if(nums[i] < nums[i-1]){
		            dp[1][i] = dp[0][i-1]+1;
		            dp[0][i] = dp[0][i-1];
		        }
		        else{
		            dp[1][i] = dp[1][i-1];
		            dp[0][i] = dp[0][i-1];
		        }
		    }
		    return max(dp[0][n-1], dp[1][n-1]);
}


