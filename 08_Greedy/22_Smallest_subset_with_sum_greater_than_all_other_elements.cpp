// This si the simple solution for this problem where we are first finding the sum of complete array and then sorting the array and subtracting the
// maximum elements from the array and get the diffrenece from the total sumand checking whether the difrenece is less than the sum or not.


class Solution{
    public:
    int minSubset(vector<int> &a,int n){
        
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        
        if(sum == 0 or n==1){
            return n;
        }
        
        sort(a.begin(), a.end());
        int idx = -1; long long sm = 0;
        for(int i=n-1; i>=0; i--){
            sm += a[i];
            long long dif = sum - sm;
            
            if(dif < sm){
                idx = i;
                break;
            }
        }
        
        return n-idx;
    }
};
