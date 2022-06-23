// Traditional recursive approach.

class Solution{
  
  public:
	void getAns(string s, int idx, int n, vector<string>& ans, string& ds){
	    if(idx == n){
	        ans.push_back(ds);
	        return;
	    }
	    
	    ds.push_back(s[idx]);
	    
	    getAns(s, idx+1, n, ans, ds);
	    
	    ds.pop_back();
	    
	    getAns(s, idx+1, n, ans, ds);
	}
	
	vector<string> AllPossibleStrings(string s){
		int n = s.length();
		vector<string> ans;
		string ds = "";
		
		getAns(s, 0, n, ans, ds);
		ans.pop_back();
		
		sort(ans.begin(), ans.end());
		
		return ans;
	}
};


// Using Power sets:
// The concept is if we are generating all the permutations of a given number (length of string) then the position of 0 in each permutation will represent 
// that the character is presemt in the string and its absence will tell that the character is excluded from the string.

class Solution{
	public:
	
	vector<string> AllPossibleStrings(string s){
	    int n = s.length();
	    vector<string> ans;
	    
		for(int i=1; i<=(1<<n)-1; i++){
		    string str = "";
		    
		    for(int j=0; j<n; j++){
		        if(i & (1<<j)){
		            str += s[j];
		        }
		    }
		    
		    ans.push_back(str);
		}
		
		sort(ans.begin(), ans.end());
		
		return ans;
	}
};
