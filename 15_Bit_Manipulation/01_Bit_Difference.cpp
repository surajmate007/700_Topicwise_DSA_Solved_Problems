// This is the logical code

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    
    int countBitsFlip(int a, int b){
        int z = a^b;
        int ans = 0;
        while(z > 0){
            ans++;
            z = z & (z-1);
        }
        
        return ans;
    }
};
