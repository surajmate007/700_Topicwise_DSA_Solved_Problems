// Exactly same approach as next next greater element.

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) { 
        stack<int> st; vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                st.push(arr[i]);
                ans[i] = -1;
            }
            else{
                while(!st.empty() and st.top() >= arr[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    ans[i] = -1;
                }
                
                else{
                    ans[i] = st.top();
                }
                
                st.push(arr[i]);
            }
        }
        
        return ans;
    } 
};
