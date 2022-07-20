// Recursion:  Recursion is accepted

class Solution {
public:
    long long int f(long long int n)
    {
        if(n==1)
            return 0;

        if(n%2==0 )
        {
             return 1+ f(n/2);
        }
        
        else
        {
            return 1+ min (f(n+1) , f(n-1));
        }
    }
    
    int integerReplacement(int n) {
        return f(n);
    }
};
