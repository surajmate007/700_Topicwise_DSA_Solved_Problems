// Very good solution approach.

class Solution {
  public:
    int findMaxLen(string s) {
       
       stack<int> st;
       int ans = 0;
       int i=0; 
       while(i<s.size()){
           if(s[i]=='(') st.push(i);
           else {
               if(!st.empty() && s[st.top()] =='(')
               {  
                   st.pop();
                   int x;
                   if(!st.empty()) {
                      x = st.top();
                   } else x=-1;
                               
                   ans = max(ans, i-x);
               }
               else {
                   st.push(i);
               }
           }
           ++i;
       }
       return ans;
   }
};
