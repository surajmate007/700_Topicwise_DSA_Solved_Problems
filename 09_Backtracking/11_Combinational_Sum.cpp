// Brute forcwe approach:

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void getAns(vector<int> a, int n, int idx, int b, vector<int>& ds, vector<vector<int>>& ans){
        if(b==0){
            ans.push_back(ds);
            return;
        }
        
        if(b < 0){
            return;
        }
        
        if(idx == n){
            return;
        }
        
        ds.push_back(a[idx]);
        getAns(a, n, idx, b-a[idx], ds, ans);
        ds.pop_back();
        getAns(a, n, idx+1, b, ds, ans);

    }
    
    vector<vector<int> > combinationSum(vector<int> &a, int B) {
        vector<int> vec;
        int n = a.size();
        sort(a.begin(), a.end());
        vec.push_back(a[0]);
        for(int i=1; i<n; i++){
            if(a[i] != vec.back()){
                vec.push_back(a[i]);
            }
        }
        
        vector<int>ds;
        vector<vector<int>> ans;
        n = vec.size();
        getAns(vec, n, 0, B, ds, ans);
        
        return ans;
    }
};




