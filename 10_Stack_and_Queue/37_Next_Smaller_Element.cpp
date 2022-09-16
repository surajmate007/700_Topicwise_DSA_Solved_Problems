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


// using dequeue:

#include<bits/stdc++.h>

vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    ans[n-1] = -1; 
    deque<int> dq; dq.push_back(arr[n-1]);
    for(int i=n-2; i>=0; i--){
        while(!dq.empty() and dq.back() >= arr[i]){
            dq.pop_back();
        }
        if(dq.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = dq.back();
        }
        dq.push_back(arr[i]);
    }
    
    return ans;
}
