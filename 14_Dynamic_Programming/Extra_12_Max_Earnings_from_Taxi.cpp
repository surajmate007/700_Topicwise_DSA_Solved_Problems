// Simple solution using DP:
// Can't say at first place that this problem can be solbved using DP:
// Link : https://leetcode.com/problems/maximum-earnings-from-taxi/


class Solution {
public:
    unordered_map<long long, vector<pair<long long, long long>>> mp;
    long long dp[100010];

    long long int getAns(int n, int pos){
        if(pos >= n){
            return 0;
        }

        if(dp[pos] != -1){
            return dp[pos];
        }

        if(mp.find(pos) != mp.end()){
            long long temp1 = INT_MIN;
            for(auto e : mp[pos]){
                temp1 = max(temp1, (e.first - pos + e.second) + getAns(n, e.first));
            }
            long long temp2 = getAns(n, pos+1);
            return dp[pos] = max(temp1, temp2);
        }
        else{
            return dp[pos] = getAns(n, pos+1);
        }

        return 0;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        mp.clear();
        memset(dp, -1, sizeof(dp));

        for(auto e : rides){
            mp[e[0]].push_back({e[1], e[2]});
        }

        return getAns(n, 1);
    }
};
