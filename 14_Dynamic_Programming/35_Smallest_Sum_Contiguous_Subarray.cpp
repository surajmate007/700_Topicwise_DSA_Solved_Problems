// Exactly opposite logic of kadane's algorithm:

// Inverted kadanes algorithm:

int smallestSumSubarray(vector<int>& a){
      int osum=INT_MAX, csum=INT_MAX; int n = a.size();
      for(int i=0; i<n; i++){
          if(osum > 0){
              osum = 0;
          }
          osum += a[i];
          if(osum < csum){
              csum = osum;
          }
      }
      return csum;
  }


// using dp approach:
int smallestSumSubarray(vector<int>& a){
      int n = a.size();
      int dp[n];
      dp[0] = a[0];
      int omin = dp[0];
      for(int i=1; i<n; i++){
          dp[i] = min(dp[i-1] + a[i], a[i]);
          omin = min(omin, dp[i]);
      }
      
      return omin;
}

