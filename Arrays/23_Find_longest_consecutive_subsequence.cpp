// we will tracverse through array and check for the start of the new sequence. 
// when we find the start of the sequence thgen we start the count by incrementing the. count and the number.

int findLongestConseqSubseq(int arr[], int N){
        int count = 0; set<int> st; int ans = 0;
        for(int i=0; i<N; i++){
            st.insert(arr[i]);
        }
        
        for(int i=0; i<N; i++){
            int n = arr[i];
            if(!st.count(n-1)){
                count = 1; 
                int p = n+1;
                while(st.count(p)){
                    count++; p++;
                }
                ans = max(ans, count);
            }
        }
        
        return ans;
    }
