// we will first sort the array and then compare it with given original array.
// We will store the indexes of elements into the map from the original array.
// then we will swap th elements in the oorigianl arrays and also swap the indexes of elements in the map.

int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    vector<int> vec(nums.begin(), nums.end());
	    sort(nums.begin(), nums.end());
	    unordered_map<int, int> mp;
	    for(int i=0; i<n; i++){
	        mp[vec[i]] = i;
	    }
	    int ans = 0;
	    for(int i=0; i<n; i++){
	        int temp1 = vec[i]; int temp2 = nums[i];
	        swap(vec[mp[temp1]], vec[mp[temp2]]);
	        swap(mp[temp1], mp[temp2]);
	        if(temp1 != temp2){
	            ans ++;
	        }
	    }
	    
	    return ans;
	}
