// we know the formula we just implemented it in code:

class Solution{
public:
    int trailingZeroes(int N){
        int ans = 0; int n = 1;
        while(N / pow(5, n) != 0){
            ans += N/pow(5, n);
            n++;
        }
        return ans;
    }
};
