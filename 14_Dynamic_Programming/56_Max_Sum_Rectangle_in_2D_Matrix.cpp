// we are finding the sum of all possible consecutive rows and applying kadanes algorithm to find max sum subarray.

class Solution {
  public:
  
  int kadane(vector<int>& arr, int n){
      int osum = 0;
      int csum = INT_MIN;
      for(int i=0; i<n; i++){
          if(osum < 0){
              osum = 0;
          }
          osum += arr[i];
          csum = max(csum, osum);
      }
      return csum;
  }
  
    int maximumSumRectangle(int n, int m, vector<vector<int>> a) {
        int k=0;
        int ans = INT_MIN;
        
        while(k < n){
            vector<int> vec(m, 0);
            for(int i=k; i<n; i++){
                for(int j=0; j<m; j++){
                    vec[j] += a[i][j];
                }
                ans = max(ans, kadane(vec, m));
            }
            k++;
        }
        
        return ans;
    }
};
