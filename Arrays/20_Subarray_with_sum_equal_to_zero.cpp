// If the prefix sum is repeating then it is confirmed that the sum is equal to zero. 


bool subArrayExists(int arr[], int n){
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(mp.find(sum) != mp.end() or sum == 0){
                return true;
            }
            else{
                mp[sum]++;
            }
        }
        return false;
    }
