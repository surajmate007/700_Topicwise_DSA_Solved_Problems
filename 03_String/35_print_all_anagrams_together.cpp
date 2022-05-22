// I have solved this problem on my own.
// The need with this problem is we have to identify all the string elements belongign to same anagram and this is only possible if we sort every
// string and check it and then store the strings on the sorted entry made for them in hashmap.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& list) {
        unordered_map<string, vector<string> >mp;
        int n = list.size();
        for(int i=0; i<n; i++){
            string s = list[i];
            string p = s;
            sort(p.begin(), p.end());
            mp[p].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto e : mp){
            vector<string> vec(e.second.begin(), e.second.end());
            ans.push_back(vec);
        }
        
        return ans;
    }
};
