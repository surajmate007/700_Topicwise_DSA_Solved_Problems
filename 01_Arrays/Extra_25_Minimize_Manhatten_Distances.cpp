// This is the must know algorithm to find the max distance between given set of 2d points.

class Solution {
public:
    vector<int> getPairs(vector<vector<int>>& points, int idx){
        int n = points.size();
        vector<vector<int>> sm, diff;
        
        for(int i=0; i<n; i++){
            if(i == idx){
                continue;
            }
            sm.push_back({points[i][0]+points[i][1], i});
            diff.push_back({points[i][0]-points[i][1], i});
        }
        
        sort(sm.begin(), sm.end());
        sort(diff.begin(), diff.end());
        n = sm.size();
        int diff1 = sm[n-1][0] - sm[0][0]; vector<int> vec1 = {sm[n-1][1], sm[0][1], diff1};
        int diff2 = diff[n-1][0] - diff[0][0]; vector<int> vec2 = {diff[n-1][1], diff[0][1], diff2};
        
        return diff1 >= diff2 ? vec1 : vec2;
    }
    
    
    int minimumDistance(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> vec = getPairs(points, -1);
        vector<int> vec1 = getPairs(points, vec[0]);
        vector<int> vec2 = getPairs(points, vec[1]);
        
        return min(vec1[2], vec2[2]);
    }
};
