// In this problem we are using stack data structure:

class Solution{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x){
        int n = x.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch = x[i];
            if(ch=='{' or ch=='(' or ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty() and ((ch==')' and st.top()=='(') or (ch==']' and st.top()=='[') or (ch=='}' and st.top()=='{'))){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }

};
