// Using the modification of LIS:


#include<bits/stdc++.h>

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> arr1 = arr;
    reverse(arr1.begin(), arr1.end());
    
    vector<int> lis(n, 1), lds(n, 1);
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                lis[i] = max({lis[i], lis[j]+1});
            }
            if(arr1[j] < arr1[i]){
                lds[i] = max({lds[i], lds[j]+1});
            }
        }
    }
    reverse(lds.begin(), lds.end());
    int ans = 0;
    
    for(int i=0; i<n; i++){
        ans = max(ans, lis[i]+lds[i]-1);
    }
    
    return ans;
}

