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
