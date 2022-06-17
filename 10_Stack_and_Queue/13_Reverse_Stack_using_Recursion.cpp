// This is the brute force approach for this problem.

class Solution{
public:
    vector<int> Reverse(stack<int> st){
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


// optimised recursve solition.


class Solution{
public:
    void getAns(stack<int> st, vector<int>& ans){
        if(st.empty()){
            return;
        }
        
        int a = st.top();
        ans.push_back(a);
        st.pop();
        getAns(st, ans);
        st.push(a);
    }
    
    vector<int> Reverse(stack<int> st){
        vector<int> ans;

        getAns(st, ans);
        
        return ans;
    }
};
