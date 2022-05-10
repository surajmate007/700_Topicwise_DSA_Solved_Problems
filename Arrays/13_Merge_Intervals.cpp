class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> pair; vector<int> vec; vec=intervals[0];
        for(int i=1; i<intervals.size(); i++){
            pair = intervals[i];
            if(vec[1] >= pair[0]){
                vec[1] = max(vec[1], pair[1]);
            }
            else{
                ans.push_back(vec);
                vec = intervals[i];
            }
        }
        ans.push_back(vec);
        
        return ans;
    }
};
