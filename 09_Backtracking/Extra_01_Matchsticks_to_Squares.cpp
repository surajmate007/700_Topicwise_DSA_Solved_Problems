// Backtracking Solution:

class Solution {
    public:
    
    bool getAns(vector<int>& ms, int n, vector<int>& used, int osum, int csum, int idx, int k){
        if(k==1){
            return true;
        }
        
        if(csum == osum){
            return getAns(ms, n, used, osum, 0, 0, k-1);
        }
        
        for(int i=idx; i<n; i++){
            if(used[i] == 0 and csum+ms[i] <= osum){
                used[i] = 1;
                if(getAns(ms, n, used, osum, csum+ms[i], i+1, k) == true){
                    return true;
                }
                used[i] = 0;
            }
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& ms){
        int n = ms.size();
        int osum = accumulate(ms.begin(), ms.end(), 0);
        if(osum%4 != 0 or ms.size() < 3){
            return false;
        }
        osum /= 4;
        
        sort(ms.begin(), ms.end(), greater<int>());
        
        vector<int> used(n, 0);

        return getAns(ms, n, used, osum, 0, 0, 4);
    }
};
