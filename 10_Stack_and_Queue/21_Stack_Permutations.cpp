// Very intuitive solution. Revise frequently.

class Solution{
public:
    int isStackPermutation(int n, vector<int> &a, vector<int> &b){
        stack<int> stk;
        int i = 0, j = 0;
        while(i < n && j < n){
            if(stk.empty()){
                stk.push(a[i++]);
            }
            else{
                if(stk.top() == b[j]){
                    while(!stk.empty() && stk.top() == b[j]){
                        stk.pop();
                        j++;
                    }
                }
                else{
                    stk.push(a[i++]);
                }
            }
        }
       
        while(!stk.empty() && j < n && stk.top() == b[j]){
            stk.pop();
            j++;
        }
       
        return (j == n ? 1 : 0);
    }
};
