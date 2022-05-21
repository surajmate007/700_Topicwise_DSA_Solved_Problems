// using unordered map, we will store required difference to get the sum inside the map and then keep 
// on searching for this value in our array.
 

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> mp; int ans = 0;
        for(int i=0; i<n; i++){
            if(mp[arr[i]] > 0){
                ans += mp[arr[i]];
            }
            if(arr[i] < k){
                mp[k-arr[i]]++;
            }
        }
        return ans;
    }
};
