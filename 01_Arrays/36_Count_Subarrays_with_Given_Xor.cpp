// simple moplementation like finding the max length subarray with sum 0.

#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x){
    int n = arr.size();
    map<int, int> mp;
    int val = 0; int ans = 0;
    
    for(int i=0; i<n; i++){
        val ^= arr[i];
        
        if(val == x){
            ans++;
        }
        int nv = val ^ x;
        if(mp.find(nv) != mp.end()){
            ans += mp[nv];
        }
        mp[val]++;
    }
    
    return ans;
}
