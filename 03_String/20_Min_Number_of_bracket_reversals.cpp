// we will keep track of both open and close and then finalize the number of brackets to be reversed.

int countRev (string s){
   stack<char> st;
   int n = s.length();
   if(n%2 == 1){
       return -1;
   }
   int open = 0; int close = 0;
   for(int i=0; i<n; i++){
       char ch = s[i]; 
       if(ch == '{'){
           st.push(ch);
           open++;
       }
       else if(ch == '}' and !st.empty() and st.top()=='{'){
           st.pop(); open--;
       }
       else{
           close++;
       }
   }
   
   int ans = (open%2 + open/2 + close%2 + close/2);
   return ans;
}
