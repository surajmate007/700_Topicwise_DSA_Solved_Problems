// using Binary search approach.
// when the value of square is less than the target then we can store it as temp answer and then move the low value to mid + 1.

class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0; long long hi = x;
        long long ans = 0;
        
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            long long sqr = mid * mid;
            
            if(sqr <= x){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};
