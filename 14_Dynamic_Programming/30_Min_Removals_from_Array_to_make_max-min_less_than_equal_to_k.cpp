// TC = O(nlog(n))
// using sorting + sliding window technique.

class Solution{
    public:
    int removals(vector<int>& a, int k){
        sort(a.begin(), a.end());
        int n = a.size();
        int ans = 0;
        int i=0; int j=0;
        
        while(j<n){
            if(a[j]-a[i] <= k){
                j++;
                continue;
            }
            ans = max(ans, j-i);
            i++;
        }
        ans = max(ans, j-i);
        
        return n - ans;
    }
};
