// This is the KMP algorithm preprocessing part:

class Solution{
  public:		
	int lps(string s) {
	    int n = s.length(); 
	    vector<int> lps(s.size(), 0);
	    int i=1; int j=0;
	    while(i < n){
	        if(s[i] == s[j]){
	            lps[i] = j+1;
	            i++; j++;
	        }
	        else{
	            if(j==0){
	                lps[i] = 0;
	                i++;
	            }
	            else{
	                j = lps[j-1];
	            }
	        }
	    }
	    return lps[n-1];
	}
};
