// In this we are just modifying the approach the we learned to find the subsrrays with 0 sum in array section.

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<long long, long long> mp;
        mp[0] = 1;
        long long ans = 0; long long sum = 0;
        
        for(auto e : arr){
            sum += e;
            if(mp.find(sum) != mp.end()){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        
        return ans;
    }
};
