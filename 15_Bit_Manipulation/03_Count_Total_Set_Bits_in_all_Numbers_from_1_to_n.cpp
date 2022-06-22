// This is the brute froce approach to solve this problem. it is giving TLE.

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int getSet(int n){
        int ans = 0;
        while(n > 0){
            ans++;
            n = n & (n-1);
        }
        return ans;
    }
    
    int countSetBits(int n){
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            ans += getSet(i);
        }
        
        return ans;
    }
};



// More vetter approach using Mathematics:

// ans(n) = (2^(x-1) * x) + (n - 2^x + 1) + ans(n - 2^x)


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int largestPowerof2(int n){
        int x = 0;
        while((1 << x) <= n){
            x++;
        }
        
        return x-1;
    }
    
    int countSetBits(int n){
        if(n<=0){
            return 0;
        }
        
        int ans = 0;
        int x = largestPowerof2(n);
        
        ans += ((1 << (x-1)) * x);
        ans += (n - (1 << x) + 1);
        ans += countSetBits(n - (1 << x));
        
        return ans;
    }
};
