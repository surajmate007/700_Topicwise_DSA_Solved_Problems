// This algorihtm is simple.
// Our stack only contains symbos and operators.
// All the operands are collected into the string directly (result here).

string infixToPostfix(string s) {
       // Your code here
       stack<char> stack;
       unordered_map<char,int>mp;
       
       mp.insert({'^',3});
       mp.insert({'*',2});
       mp.insert({'/',2});
       mp.insert({'+',1});
       mp.insert({'-',1});
       
       string result = "";
   
       for(int i=0;i<s.size();i++){
           char currChar = s[i];
           
           if(mp.find(currChar)==mp.end()){
               if(currChar=='(')
                   stack.push(currChar);
               else if (currChar==')'){
                   while(!stack.empty()&&stack.top()!='('){
                      result+=stack.top();
                      stack.pop();
                   }
                      
                   stack.pop();
                   
               }
               else {
                   result+=currChar;
               }
               
           }
           else{
               while(!stack.empty()&&stack.top()!='('&&mp[stack.top()]>=mp[currChar]){
                   result+=stack.top();
                   stack.pop();
               }   
               stack.push(currChar);
               }
       }
       while(!stack.empty()){
           result+=stack.top();
           stack.pop();
       }
       return result;
   }
