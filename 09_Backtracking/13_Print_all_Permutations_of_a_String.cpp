// Solution by backtracking.

class Solution{
	public:
	
	    set<string> getPerm(string s, int n, set<string>& st, string& ds, vector<int>& freq){
	        if(ds.size() == s.size()){
	            st.insert(ds);
	        }
	        
	        for(int i=0; i<n; i++){
	            if(freq[i] != 1){
	                ds.push_back(s[i]);
	                freq[i] = 1;
	                getPerm(s, n, st, ds, freq);
	                freq[i] = 0;
	                ds.pop_back();
	            }
	        }
	        return st;
        }	    
	
		vector<string>find_permutation(string s){
		   int n = s.length();
		   set<string> st;
		   string ds = "";
		   vector<int> freq(n, 0);
		   set<string> res = getPerm(s, n, st, ds, freq);
		   vector<string> ans(res.begin(), res.end());
		   return ans;
		}
};


// Solution without backtracking and efficient:

class Solution{
	public:
	
	    void getPerm(int idx, string s, set<string>& st){
	        if(idx == s.length()){
	            st.insert(s);
	            return;
	        }
	        
	        for(int i=idx; i<s.length(); i++){
	            swap(s[idx], s[i]);
	            getPerm(idx+1, s, st);
	            swap(s[idx], s[i]);
	        }
      }	    
	
		vector<string>find_permutation(string s){
		   int n = s.length();
		   set<string> st;
		   getPerm(0, s, st);
		   vector<string> ans(st.begin(), st.end());
		   return ans;
		}
};
