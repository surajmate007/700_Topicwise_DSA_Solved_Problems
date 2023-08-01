leetcode problem : 77

  
class Solution {
public:

    void getCombo(vector<vector<int>>& ans, vector<int>& vec, vector<int>& taken, int n, int k, int mn){
        if(k == 0){
            ans.push_back(vec);
            return;
        }

        for(int i=mn; i<n; i++){
            if(taken[i] == 0){
                taken[i] = 1;
                vec.push_back(i+1);
                getCombo(ans, vec, taken, n, k-1, i+1);
                vec.pop_back();
                taken[i] = 0;
            }
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vec;
        vector<int> taken(n, 0);
        getCombo(ans, vec, taken, n, k, 0);
        return ans;
    }
};
