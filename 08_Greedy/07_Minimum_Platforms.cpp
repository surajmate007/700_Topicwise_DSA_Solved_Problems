class Solution{
  public:
    
    int findPlatform(int arr[], int dep[], int n){
    	
    	sort(arr, arr+n);
    	sort(dep, dep+n);
      
    	int i=1; int j=0;
    	int cnt = 1; int ans = 0;
    	while(i<n and j<n){
    	    if(arr[i] <= dep[j]){
    	        cnt++; i++;
    	    }
    	    
    	    else{
    	        cnt--; j++;
    	    }
    	    
    	    ans = max(ans, cnt);
    	}
    	
    	return ans;
    }
};
