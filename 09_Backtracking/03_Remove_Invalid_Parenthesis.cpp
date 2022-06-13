// Here we are using map to avoid duplicates.
// The same function min_removals will tell us whether the string is valid parenthesis or not and also tell us the minimum number of removals
// to make the string balanced. The non zero output means not balanced.
// We are very elegently removing the character from the string using left and right substrings.

class Solution {
public:
    vector<string>ans;
    unordered_map<string,int>m;
    
    int min_removal(string str){
        stack<char>s;
        int i=0;
        while(i<str.size()){
            
            if(str[i]=='(')
                s.push(str[i]);
            else if(str[i]==')'){
                if(s.size()>0 && s.top()=='(')
                    s.pop();
                else
                    s.push(')');
            }
                
            i++;
            
        }
        return s.size();
    }
    
    void solve(string str,int b){
        if(m[str])
            return;
        else
            m[str]++;
        if(b==0){
            if(!min_removal(str)){
                ans.push_back(str);
                return;
            }
                
        }
        for(int i=0;i<str.size();i++){
            string left=str.substr(0,i);
            string right=str.substr(i+1);
            solve(left+right,b-1);
        }
        return;
    }
    
    vector<string> removeInvalidParentheses(string str) {
        int k=min_removal(str);
        solve(str,k);
        return ans;
    }
};
