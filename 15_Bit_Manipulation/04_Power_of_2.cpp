// This is the easiest approach for this problem but giving TLE.

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        int x = 0;
        if(n==1){
            return true;
        }
        
        while(1){
            
            if(n%2 == 1){
                return false;
            }
            
            if(n==2){
                return true;
            }
            
            n = n/2;
        }
        
        return false;
    }
};

// This is the better way of solving this using maths.

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        if(n==0){
            return false;
        }
        
        int val = n & (n-1);
        
        if(val == 0){
            return true;
        }
        else return false;
    }
};
