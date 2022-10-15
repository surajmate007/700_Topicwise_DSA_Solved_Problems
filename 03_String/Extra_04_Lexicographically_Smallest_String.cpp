// simple solution.
// Algorithm to form smallest string is important to revise.


class Solution {
  public:
    bool setBits(int n){
        if(n==0){
            return false;
        }
        return ceil(log2(n)) == floor(log2(n));
    }
    
    string lexicographicallySmallest(string s, int k) {
        int n = s.length();
        if(setBits(n)){
            k /= 2;
        }
        else{
            k *= 2;
        }
        
        string ans = "";
        for(int i=0; i<n; i++){
            while(ans.size() and k and ans.back() > s[i]){
                ans.pop_back();
                k--;
            }
            ans.push_back(s[i]);
        }
        
        while(ans.size() and k--){
            ans.pop_back();
        }
        
        if(ans.size() == 0){
            return "-1";
        }
        return ans;
    }
};
