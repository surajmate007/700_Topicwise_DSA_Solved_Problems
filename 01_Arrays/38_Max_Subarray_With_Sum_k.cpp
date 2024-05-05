// if the array contains only positive elements then this is most optimal.
int longestSubarrayWithSumK(vector<int> a, long long k) {
   int n = a.size();
   int i=0; int j=0; int ans = 0;

   while(j<n){
       k -= a[j]; j++;
       if(k == 0) ans = max(ans, j-i);
       while (k < 0 and i < j) {
            k += a[i]; i++;
            if(k == 0) ans = max(ans, j-i);
       }
   }

   return ans;
}


// if the subarray contains both +ve and -ve elements then this is most optimal.
#include <bits/stdc++.h> 
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    int n = nums.size(); int ans = 0;
    unordered_map<int, int> mp; int sum = 0; mp[0] = -1;
    for(int i=0; i<n; i++){
        sum += nums[i];
        int tar = sum - k;
        if(mp.find(tar) != mp.end()){
            ans = max(ans, i-mp[tar]);
        } 
        if(mp.find(sum) == mp.end()) mp[sum] = i;
    }

    return ans;
}
