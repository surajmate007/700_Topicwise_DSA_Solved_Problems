long long maxProduct(vector<int> arr, int n) {
	    long long ma = arr[0], mi = arr[0], ans = arr[0];
	    for(int i=1; i<n; i++){
	        if(arr[i] < 0){
	            swap(ma, mi);
	        }
	        ma = max((long long)arr[i], ma * (arr[i]));
	        mi = min((long long)arr[i], mi * (arr[i]));
	        ans = max(ans, ma);
	    }
	    return ans;
	}
