// first find nums[i] < nums[i+1] and mark i as index1. if idx1 == -1 then simply reverse that array.
// Then find nums[i] > nums[index1] then mark that i as index2.
// swap elements at index1 and index2 and then reverse the array after index1.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx1 = -1; int idx2 = -1; int n = nums.size()-1;
        
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx1 = i;
                break;
            }
        }
        
        if(idx1 == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i=n; i>=0; i--){
            if(nums[i] > nums[idx1]){
                idx2 = i;
                break;
            }
        }
        
        swap(nums[idx1], nums[idx2]);
        reverse(nums.begin() + idx1 + 1, nums.end());
 
        return;
    }
};


// Previous Smaller Element:
// similar concept of next permutation:
// we are first finding the index from last which satisfy a[idx1] > a[idx1+1]; After finding such idx then we will find the last smaller element from right
// ie: a[idx2] < a[idx1] then we will swap the elements at idx1 and idx2 we will sort the array from idx+1 in descending order.


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lastSmallest(vector<int>& arr, int n){
    int idx1 = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i+1]){
            idx1 = i;
            break;
        }
    }
    
    if(idx1 == -1){
        return -1; 
    }
    int idx2 = -1;
    for(int i=n-1; i>idx1; i--){
        if(arr[i] < arr[idx1]){
            idx2 = i;
            break;
        }
    }
    
    swap(arr[idx1], arr[idx2]);
    sort(arr.begin()+idx1+1, arr.end(), greater<int>());
    int ans = 0;
    int i=0; 
    
    for(int i=0; i<n; i++){
        ans = ans*10 + arr[i];
    }
    
    return ans;
}


int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int ans = lastSmallest(arr, n);
    cout<<ans<<endl;
    
    return 0;
};
