// The only set bit will appear into those numbers which are power of 2.
// In other numbers we will return -1.

class Solution{
  public:
    int findPosition(int n) {
        if(n == 0){
            return -1;
        }
        
        int val = n & (n-1);
        
        if(val == 0){
            return log2(n)+1;
        }
        
        return -1;
    }
};
