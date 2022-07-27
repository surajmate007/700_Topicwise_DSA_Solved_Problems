class Solution {
public:
    bool isPerfectSquare(int num) {
        long long lo = 0; long long hi = num;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            long long sqr = mid * mid;
            
            if(sqr == num){
                return true;
            }
            
            else if(sqr < num){
                lo = mid + 1;
            }
            
            else{
                hi = mid - 1;
            }
        }
        
        return false;
    }
};
