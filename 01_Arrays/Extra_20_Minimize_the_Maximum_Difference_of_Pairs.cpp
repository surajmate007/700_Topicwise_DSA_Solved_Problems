// This is the dp approach for this problem but memory limit is getting exceeded.

class Solution {
public:
    vector<vector<int>> dp;

    int getAns(vector<int>& diff, int n, int p, int idx){
        if(p == 0){
            return 0;
        }
        if(idx >= n){
            return INT_MAX;
        }

        if(dp[idx][p] != -1){
            return dp[idx][p];
        }

        int ans1 = max(diff[idx], getAns(diff, n, p-1, idx+2));
        int ans2 = getAns(diff, n, p, idx+1);

        return dp[idx][p] = min(ans1, ans2);
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> diff;
        for(int i=0; i<n; i++){
            diff.push_back(abs(nums[i] - nums[(i+1)%n]));
        }
        dp.clear();
        dp.resize(n+1, vector<int>(p+1, -1));

        int ans = getAns(diff, n, p, 0);
        return ans;
    }
};



// This is the bianry search approach for this problem.

class Solution {
public:
    bool arePairsPossible(vector<int>& nums, int p, int mid){
        int n = nums.size();

        for(int i=0; i<n-1 and p > 0;){
            int diff = nums[i+1] - nums[i];
            if(diff <= mid){
                p--;
                i++ ;
            }
            i++;
        }
        if(p == 0){
            return true;
        }

        return false;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int lo = 0; int hi = nums[n-1] - nums[0];
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(arePairsPossible(nums, p, mid)){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    }
};
