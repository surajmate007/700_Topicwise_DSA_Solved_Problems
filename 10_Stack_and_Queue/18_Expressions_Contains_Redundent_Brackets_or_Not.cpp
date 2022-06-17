// The idea is to use stack, which is discussed in this article. For any sub-expression of expression, if we are able to pick any sub-expression of
// expression surrounded by (), then we again left with () as part of string, we have redundant braces. 
// We iterate through the given expression and for each character in the expression, if the character is an open parenthesis ‘(‘ or any of the operators
// or operands, we push it to the stack. If the character is close parenthesis ‘)’, then pop characters from the stack till matching open parenthesis
// ‘(‘ is found. 
// Now for redundancy two condition will arise while popping- 
 
// If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b.
// When we reach the second “)” after a+b, we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate
// brackets. 
// If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression.
// For instance, (a)+b contain unwanted () around a thus it is redundant. 


bool checkRedundancy(string& str){
    stack<char>s;
    int i=0;
    while(i!=str.size()){
        if(str[i]==')'){
            if(s.top()=='('){
                return true;
            }
            int x=0;
            while(s.top()!='('){
                s.pop();
                x++;
            }
            s.pop();
            if(x==1)
            return true;
        }
        else{
            s.push(str[i]);
            i++;
        }
    }
    return false;
}
