// This is the recursive code but giving TLE

int minop(vector<int> a, int i, int j, int x, int ans){
        if(x == 0){
            return ans;
        }
        
        if(a[i] > x and a[j] > x){
            return INT_MAX;
        }
        
        if(x < 0){
            return INT_MAX;
        }
        
        return min(minop(a, i+1, j, x-a[i], ans+1), minop(a, i, j-1, x-a[j], ans+1));
        
}


// More optimised solution:
// Here instead of finding the sum of K from the given array elements we are finding the sum of (sum of total array elements - k) from the 
// subarray and then we will try to find the maximum window size having this sum.
// After finding the max window sixe we will subtract this window size from the length of the array.

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long tsum = 0;
        for(int i=0; i<n; i++){
            tsum += (long long)nums[i];
        }
        long long tar = tsum - (long long) x;
        int ans = INT_MIN;

        int p=0; int q=0; long long sum = 0;
        while(q < n){
            sum += (long long)nums[q];
            q++;
            while(p<q and sum > tar){
                sum -= (long long)nums[p];
                p++;
            }
            if(sum == tar){
                ans = max(ans, q-p);
            }
        }
        return ans == INT_MIN ? -1 : n-ans;
    }
};


// same approach

class Solution {
public:
    
  
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        int sum = 0; int ans = 0;
        
        for(int i=0; i<n; i++){
            sum += a[i];
        }
        
        if(sum == x){
            return n;
        }
        
        int tar = sum - x;
        sum = 0;
        
        int i=0; int j=0;
        while(j < n){
            sum += a[j];
            j++;
            
            if(sum >= tar){
                while(sum > tar and i<j){
                    sum -= a[i];
                    i++;
                }
                if(sum == tar){
                    ans = max(ans, j-i);
                }
            }
        }
        
        if(ans == 0){
            return -1;
        }
        
        return n-ans;
    }
};
