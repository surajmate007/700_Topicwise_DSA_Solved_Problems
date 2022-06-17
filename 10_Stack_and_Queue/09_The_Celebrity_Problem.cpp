// This is the brute force aproach for this problem.

class Solution {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) {
        int idx = 0; bool flag = true;
        for(int i=0; i<n; i++){
            if(accumulate(a[i].begin(), a[i].end(), 0) == 0){
                idx = i;
                for(int j=0; j<n; j++){
                    if((j!=idx and a[j][idx]==0) or (j==idx and a[j][idx]==1)){
                        flag = false;
                    }
                }
                if(flag){
                    return idx;
                }
            }
        }
        
        return -1;
    }
};


// Optimised Approach:
// Here we are first loading all the peorsons into the stack and then poping out 2 members and comparing them for celebrity conditions.
// If anyone of them satisfies the celebrity condition then we are pushing that member back into the stack.
// thus we keep on reducing the size of the stack.
// When the size reaches to 1 then we will traverse over the array and check whether the person is really the celebrity or not.


class Solution {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) {
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }

        while(st.size() > 1){
            int m1 = st.top(); st.pop();
            int m2 = st.top(); st.pop();
            if(a[m1][m2] == 0 and a[m2][m1] == 1){
                st.push(m1);
            }
            else if(a[m2][m1] == 0 and a[m1][m2] == 1){
                st.push(m2);
            }
        }
        
        if(st.empty()){
            return -1;
        }
        
        int m = st.top(); st.pop();
        for(int i=0; i<n; i++){
            if((i!=m) and (a[m][i] != 0 or a[i][m] != 1) or a[m][m] == 1){
                return -1;
            }
        }
        return m;
    }
};
