class Solution{
  public:
    long long int maximizeSum(long long int a[], int n, int k){
        sort(a, a+n);
        
        for(int i=0; i<n; i++){
            if(a[i] < 0 and k > 0){
                a[i] = -1 * a[i];
                k--;
            }
            else{
                break;
            }
        }
        
        if(k){
            sort(a, a+n);
            if(k%2){
                a[0] = -1 * a[0];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += a[i];
        }
        
        return ans;
    }
};
