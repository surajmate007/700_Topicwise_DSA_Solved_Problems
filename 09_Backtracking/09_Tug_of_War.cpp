// Solved in the conventional way of pick or not pick.
// This way of solving is not optimised. Giving TLE

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getAns(vector<int> a, int n, int ctr, int idx, int& ans, int csum, int osum){
    if(ctr==0){
        ans = min(ans, abs(osum-2*csum));
        return;
    }
    
    if(idx == n){
        return;
    }
    
    getAns(a, n, ctr-1, idx+1, ans, csum+a[idx], osum);
    
    getAns(a, n, ctr, idx+1, ans, csum, osum);
}

int tugOfWar(vector<int> &arr, int n){
    int osum = 0;
    for(int i=0; i<n; i++){
        osum += arr[i];
    }
    int ans = INT_MAX;
    
    int ctr;
    if(n%2) ctr = n/2+1;
    else ctr = n/2;

    getAns(arr, n, ctr, 0, ans, 0, osum);
    
    return ans;
}
