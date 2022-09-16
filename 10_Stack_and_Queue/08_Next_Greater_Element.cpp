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



// Sinple code using dqueue for next greater element:

#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n); ans[n-1] = -1;
    deque<int> dq; dq.push_back(arr[n-1]);
    for(int i=n-2; i>=0; i--){
        while(!dq.empty() and dq.back() <= arr[i]){
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


// simple code using dequeue for next samller element:


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
