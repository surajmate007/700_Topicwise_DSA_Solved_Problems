// this solution is written by me and I am using Kadane's algorithm for this where '1' means -1 and '0' means 1 and thus we will
// find the max sum in the contiguous array.

class Solution{
public:	
	int maxSubstring(string s){
	    int n = s.length();
	    int arr[n];
	    
	    for(int i=0; i<n; i++){
	        if(s[i] == '0'){
	            arr[i] = 1;
	        }
	        else{
	            arr[i] = -1;
	        }
	    }
	    
	    int osum = 0; int csum = 0;
	    for(int i=0; i<n; i++){
	        if(osum < 0){
	            osum = 0;
	        }
	        osum += arr[i];
	        if(csum < osum){
	            csum = osum;
	        }
	    }
	    
	    if(csum == 0){
	        return -1;
	    }
	    
	    return csum;
	}
};
