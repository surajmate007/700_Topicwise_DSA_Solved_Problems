// we are using modification of max area histogram problem. In max area histogram problem we only have one array and we find the left and right
// limit for that array and then find the corresponding area of the rectangle.
// But in case of max ares rectangle problem we will keep on making such arrays by adding the consecutive rows and then we will keep on checking
// max area that can be formed out of these arrays.

class Solution{
  public:
    int getArea(vector<int> arr, int m){
        stack<int> st;
        int ans = 0;
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
            
            int area = (right[i] - left[i] + 1) * arr[i];
            ans = max(area, ans);
        }
    
        return ans;
    } 
    
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> vec(m, 0); int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] == 0){
                    vec[j] = 0;
                }
                else{
                    vec[j] += M[i][j];
                }
            }
            ans = max(ans, getArea(vec, m));
        }
        
        return ans;
    }
};
