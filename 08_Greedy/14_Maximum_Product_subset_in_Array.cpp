// we are first finding the product of all the numbers and then seperately handling the edge cases.

class Solution{
    public:
    
    int mod=1000000007;
    long long int findMaxProduct(vector<int>&a, int n){
        if (n == 1)
        return a[0];

        int max_neg = INT_MIN;
       int count_neg = 0, count_zero = 0;
       long long int prod = 1;
       for (int i = 0; i < n; i++) {
           if (a[i] == 0) {
               count_zero++;
               continue;
           }
           if (a[i] < 0) {
               count_neg++;
               max_neg = max(max_neg, a[i]);
           }
    
           prod = (prod * a[i])%mod;
       }
       
       if (count_zero == n)
           return 0;
    
       if (count_neg%2){
           if (count_neg == 1 &&
               count_zero > 0 &&
               count_zero + count_neg == n)
               return 0;
           prod = prod / max_neg;
       }
    
       return prod;
    }
};
