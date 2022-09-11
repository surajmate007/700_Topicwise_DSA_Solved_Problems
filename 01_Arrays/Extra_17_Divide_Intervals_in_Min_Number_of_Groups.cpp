https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0; int n = intervals.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0][1]);
        
        for(int i=1; i<n; i++){
            if(pq.top() < intervals[i][0]){
                pq.pop();
            }
            pq.push(intervals[i][1]);
        }
        
        return pq.size();
    }
};
