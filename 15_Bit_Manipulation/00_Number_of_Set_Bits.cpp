// Popular algorithm.

class Solution{
  public:
    int setBits(int N) {
        int ans = 0;
        while(N > 0){
            ans++;
            N = N & (N-1);
        }
        
        return ans;
    }
    
};
