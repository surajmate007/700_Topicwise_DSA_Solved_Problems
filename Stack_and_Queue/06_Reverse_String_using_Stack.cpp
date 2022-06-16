// Easy solution.
// first store the complete string into the stack amd the pop out the string from the stack.

//return the address of the string
char* reverse(char *s, int len){
    stack<char>st;
    for(int i=0; i<len; i++){
        st.push(s[i]);
    }
    for(int i=0; i<len; i++){
        s[i] = st.top();
        st.pop();
    }
    
    return s;
}
