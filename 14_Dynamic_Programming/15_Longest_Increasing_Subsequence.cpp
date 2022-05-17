// we will create temp vector and add first element to that vector. then we will keep on checking whether the next element is in array is greater than last 
// element in vector. if it is then push it to vector else find its perfect position in vector using binary search and put that element on its perfect
// position. TC = O(Nlog(n)) SC = O(n)


class Solution{
    public:
    //Function to find length of longest increasing subsequence.
    // complete binary search function can be replaced by lower bound in c++
    // ie lower bound of any value to search in vector is :          int low = lower_bound(vec.begin(), vec.end(), val);
    void binaerysrch(vector<int>& vec, int val){
        int lo = 0;
        int hi = vec.size()-1;
        int mid;
        while(lo < hi){
            mid = (hi+lo)/2;
            if(vec[mid] > val){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        vec[lo] = val;
    }
    
    int longestSubsequence(int n, int a[]){
       vector<int> temp;
       temp.push_back(a[0]);
       int len = 1;
       for(int i=1; i<n; i++){
           if(a[i] > temp.back()){
               temp.push_back(a[i]);
               len++;
           }
           else{
               binaerysrch(temp, a[i]);
           }
       }
       return len;
    }
};


// Another solution which takes O(n2) TC:
// the above solution does not give the exact LIS array elements hence this new approach can be used which can be further modified
// to find the total sum of LIS elements.

int longestSubsequence(int n, int a[]){
       int dp[n+1];
       for(int i=0; i<n; i++){
           dp[i] = 1;
       }
       int ans = 0;
       for(int i=0; i<n; i++){
           for(int j=0; j<i; j++){
               if(a[i] > a[j] and dp[j]+1 > dp[i]){
                   dp[i] = dp[j]+1;
                   ans = max(ans, dp[i]);
               } 
           }
       }      
       return ans;
}
