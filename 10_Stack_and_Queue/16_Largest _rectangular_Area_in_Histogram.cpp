class solution{
  public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int m){
        stack<int> st;
        long long ans = 0;
        vector<int> left(m, 0), right(m, 0);
      
        for(int i=0; i<m; i++){
            if(st.empty()){
                left[i] = 0; st.push(i);
            }
            else{
                while((!st.empty() and arr[st.top()] >= arr[i])){
                    st.pop();
                }
                if(st.empty()){
                    left[i] = 0;
                }
                else{
                    left[i] = st.top()+1;
                }
                st.push(i);
            }
        }
        
        stack<int> nst;
        
        for(int i=m-1; i>=0; i--){
            if(nst.empty()){
                right[i] = m-1; nst.push(i);
            }
            else{
                while(!nst.empty() and arr[nst.top()] >= arr[i]){
                    nst.pop();
                }
                if(nst.empty()){
                    right[i] = m-1;
                }
                else{
                    right[i] = nst.top()-1;
                }
                nst.push(i);
            }
            
            long long area = (right[i] - left[i] + 1) * arr[i];
            ans = max(area, ans);
        }
    
        return ans;
    }
};
