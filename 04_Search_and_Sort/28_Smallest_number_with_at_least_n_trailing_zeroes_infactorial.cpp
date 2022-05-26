// We know the answer space hence we will apply binary search approach:

class Solution{
    public:
        int solve(int n){
            if(n<= 1){
                return n;
            }
            return n + solve(n/5);
        }
        
        int findNum(int n){
            int lo = 1; int hi = n;
            while(lo <= hi){
                int mid = (lo + hi)/2;
                int x = solve(mid);
                if(x >= n){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
            
            return 5 * lo;
        }
};
