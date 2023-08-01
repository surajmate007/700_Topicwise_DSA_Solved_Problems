// first sort the intervals then consider one interval and compare upper adn lower limits and keep on merging. wjhen not possible to mmerge push that
// updated interval inside the array and consider another new interval and do the same thing atlast push the last interval.

// beats 99.11% solutions
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0]; int end = intervals[0][1];

        for(int i=0; i<n; i++){
            if(intervals[i][0] > end){
                ans.push_back({start, end});
                start = intervals[i][0]; end = intervals[i][1];
            }
            else{
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};


// beats only 11% solutions
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
