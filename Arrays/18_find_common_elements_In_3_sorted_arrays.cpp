// brute force

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int> ans;
            vector<int> cmn;
            int i=0; int j=0;
            while(i<n1 and j<n2){
                if(A[i] == B[j]){
                    cmn.push_back(A[i]);
                    i++; j++;
                }
                else if(A[i] < B[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            set<int> st;
            i=0; j=0;
            while(i<cmn.size() and j<n3){
                if(cmn[i] == C[j]){
                    st.insert(cmn[i]);
                    i++; j++;
                }
                else if(cmn[i] < C[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            for(auto ele : st){
                ans.push_back(ele);
            }
            
            return ans;
        }

// optimal

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            vector<int> ans;
            int last = INT_MAX;
            int i=0, j=0, k=0;
            while(i<n1 and j<n2 and k<n3){
                if(A[i]==B[j] and A[i]==C[k] and A[i]!=last){
                    ans.push_back(A[i]);
                    last = A[i];
                    i++; j++; k++;
                }
                else if(min(A[i], B[j], C[k]) == A[i]){
                    i++;
                }
                else if(min(A[i], B[j], C[k]) == B[j])){
                    j++;
                }
                else{
                    k++;
                }
            }
            return ans;
}
