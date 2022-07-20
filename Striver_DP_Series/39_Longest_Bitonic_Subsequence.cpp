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



// Similar Approach of longets bitonic subsequence:
// Longest mountain in array:


class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> narr = arr;
        reverse(narr.begin(), narr.end());
        
        int n = arr.size();
        
        vector<int> lis (n, 1), lds(n, 1);
        
        for(int i=1; i<n; i++){
            if(arr[i] > arr[i-1]){
                lis[i] = lis[i-1]+1;
            }
            if(narr[i] > narr[i-1]){
                lds[i] = lds[i-1]+1;
            }
        }
        
        reverse(lds.begin(), lds.end());
        
        int ans = 0;
        for(int i=0; i<n; i++){
            if(lis[i] != 1 and lds[i] != 1){
                ans = max(ans, lis[i]+lds[i]-1);
            }  
        }
        
        return ans;
    }
};


