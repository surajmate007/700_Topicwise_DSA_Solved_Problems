// First sortting the array and then finding the min sum and max sum from start and end respectively.

class Solution{ 
  public:
    vector<int> candyStore(int candies[], int N, int K){
        vector<int> ans;
        sort(candies, candies+N);
        int cnt = 0; int lo = 0, hi = 0;
        
        for(int i=0; i<N; i++){
            
            cnt++; lo += candies[i]; hi += candies[N-i-1];
            cnt += K;
            if(cnt >= N){
                ans = {lo, hi};
                break;
            }
        }
        
        return ans;
    }
};
