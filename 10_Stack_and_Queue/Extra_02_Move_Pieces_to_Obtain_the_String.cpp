// Leetcode contest 301 : Problem Number 2337
// Whenever we need to maintain order in strings it is more probably that such problems will be solved using stack.

class Solution {
public:
    bool canChange(string s1, string s2) {
        int n = s1.length();
        stack<pair<char, int>> st;
        
        for(int i=n-1; i>=0; i--){
            if(s2[i] != '_'){
                st.push({s2[i], i});
            }
        }
        
        for(int i=0; i<n; i++){
            if(s1[i] == '_'){
                continue;
            }
            else{
                if(st.empty()){
                    return false;
                }
                
                auto e = st.top(); st.pop();
                
                if(s1[i] == e.first){
                    if(s1[i] == 'L'){
                        if(i < e.second){
                            return false;
                        }
                    }
                    else{
                        if(i > e.second){
                            return false;
                        }
                    }
                }
                else{
                    return false;
                }
            }
        }
        
        if(st.size() > 0){
            return false;
        }
        
        return true;
    }
};
