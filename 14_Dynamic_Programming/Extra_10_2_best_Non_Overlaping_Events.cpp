// Here combination of binary search with dynamic programming is used:


class Solution {
public:
    
    int getAns(vector<vector<int>>& events, int n, int idx, unordered_map<string, int>& dp, int rem){
        if(idx >= n){
            return 0;
        }
        
        if(rem == 0){
            return 0;
        }
        
        string s = to_string(idx) +"_"+ to_string(rem);
        if(dp.find(s) != dp.end()){
            return dp[s];
        }
        
        int ans1 = 0; int ans2 = 0;
        ans2 = getAns(events, n, idx+1, dp, rem);
        
        // Binary search to search the next possible event.
        int lo = idx+1; int hi = n-1; int nidx = n;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(events[mid][0] > events[idx][1]){
                nidx = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        ans1 = events[idx][2] + getAns(events, n, nidx, dp, rem-1);
        return dp[s] = max(ans1, ans2);
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end()); // since we will binary search for 1st value hence we will sort according to the first value.
        
        unordered_map<string, int> dp;
        return getAns(events, n, 0, dp, 2);
    }
};
