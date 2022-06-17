// easy traverse from the back of the array and then keep on finding the next greater element on the top of the stack.
// If the greater element is not present on the top of the stacj then pop the element of the stack.
// If after poping the stack is empty thta means no greater element is present and we will put -1 elese we will put top of the stack as an amswer.

class Solution{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> a, int n){
        vector<long long> ans(n); stack<long long>st;
        
        for(long long i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(a[i]);
                ans[i] = -1;
            }
            else{
                while(!st.empty() and st.top() < a[i]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top();
                }
                else{
                    ans[i] = -1;
                }
                st.push(a[i]);
            }
        }
        
        return ans;
    }
};
