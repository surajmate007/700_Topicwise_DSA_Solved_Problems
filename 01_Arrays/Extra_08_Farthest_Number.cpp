// here we have to find the farthest number from the given number which is also less than the number and farthest to the right.

class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i] = min(suffix[i+1], arr[i]);
        }
        
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int idx = lower_bound(suffix.begin(), suffix.end(), arr[i])-suffix.begin()-1;
            
            if(idx < i){
                ans[i] = -1;
            }
            else{
                ans[i] = idx;
            }
            
        }
        
        return ans;
    }
};
