// very easy

class Solution{
public:
    long long findMinSum(vector<int> &a, vector<int> &b, int n){
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long ans = 0;
        
        for(int i=0; i<n; i++){
            ans += abs(a[i] - b[i]);
        }
        
        return ans;
    }
};
