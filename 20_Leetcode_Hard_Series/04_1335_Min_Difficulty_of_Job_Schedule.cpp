// revise frequently. 
// simple dp based solution.

class Solution {
public:

    int dp[310][12][1010];
    int getAns(vector<int>& jd, int n, int idx, int d, int mx){
        if(d<=0){
            return 1e9;
        }
        if(idx >= n){
            if(d==1){
                return mx;
            }
            return 1e9;
        }

        if(dp[idx][d][mx] != -1){
            return dp[idx][d][mx];
        }

        int ans1 = mx + getAns(jd, n, idx+1, d-1, jd[idx]);
        int ans2 = getAns(jd, n, idx+1, d, max(mx, jd[idx]));

        return dp[idx][d][mx] = min(ans1, ans2);
    }

    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n==d){
            return accumulate(jd.begin(), jd.end(), 0);
        }
        if(d > n){
            return -1;
        }
        memset(dp, -1, sizeof(dp));
        return getAns(jd, n, 1, d, jd[0]);
    }
};
