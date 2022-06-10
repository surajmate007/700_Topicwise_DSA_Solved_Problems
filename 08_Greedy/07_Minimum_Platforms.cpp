// Here the approach is simple we are first sorting the train arrival and departure times and then we will use 2 pointers on different arrays and 
// see whether before arrival of next train any train deparets or not. If the train departs then we wont need any extra platform but if the 
// train train doesn't depart before the ariival of next train then we will nedd one extra platform.


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
