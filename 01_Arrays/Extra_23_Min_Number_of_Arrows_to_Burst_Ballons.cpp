// this problem is similar to finding max overlaps.

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int mx = points[0][1];
        int ans = 0;

        for(int i=0; i<n; i++){
            if(mx < points[i][0]){
                mx = points[i][1];
                ans++;
            }
            else{
                mx = min(mx, points[i][1]);
            }
        }

        return ans+1;

    }
};
