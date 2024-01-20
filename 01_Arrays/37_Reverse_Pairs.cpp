// Exactlty similar approach like merge sort:

#include <bits/stdc++.h> 

int merge(vector<int>& arr, int lo, int mid, int hi){
    vector<int> temp; int ans = 0;
    int i = lo; int j = mid+1;
    
    while(i <= mid and j <= hi){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            int idx = upper_bound(arr.begin()+lo, arr.begin()+mid+1, 2*arr[j]) - arr.begin();
            ans += (mid - idx + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= hi){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(int k=lo; k<=hi; k++){
        arr[k] = temp[k-lo];
    }
    
    return ans;
}

int mergeSort(vector<int>& arr, int lo, int hi){
    int ans = 0;
    if(lo < hi){
        int mid = lo + (hi - lo)/2;
        ans += mergeSort(arr, lo, mid);
        ans += mergeSort(arr, mid+1, hi);
        ans += merge(arr, lo, mid, hi);
    }
    
    return ans;
}

int reversePairs(vector<int> &arr, int n){
    return mergeSort(arr, 0, n-1);
}
