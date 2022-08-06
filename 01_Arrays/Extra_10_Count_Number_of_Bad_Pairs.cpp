// Biweekly contest priblem.
// Easy approach we can check for the sequence of increasing number with index by storing difference of number and its index.

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long pairs = n*(n-1)/2;
        unordered_map<long long, long long>mp;
        
        for(long long i=0; i<n; i++){
            mp[nums[i]-i]++;
        }
        
        for(auto e : mp){
            if(e.second > 1){
                long long f = e.second;
                pairs -= (f*(f-1)/2);
            }
        }
        
        return pairs;
    }
};
