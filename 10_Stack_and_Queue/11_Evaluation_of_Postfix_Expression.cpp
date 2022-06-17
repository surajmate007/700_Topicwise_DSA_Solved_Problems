// This is simple solution using stack.

class Solution{
  public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s){
        int n = s.length();
        stack<int> st;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch-'0'>=0 and ch-'0'<=9){
                st.push(ch-'0');
            }
            else{
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();
                if(ch=='+'){
                    st.push(n2+n1);
                }
                else if(ch=='-'){
                    st.push(n2-n1);
                }
                else if(ch=='*'){
                    st.push(n1*n2);
                }
                else{
                    st.push(n2/n1);
                }
            }
        }
        
        return st.top();
    }
};
