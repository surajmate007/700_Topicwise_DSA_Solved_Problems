class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        set<int> st;
        for(int i=0; i<n; i++){
            st.insert(a[i]);
        }
        for(int i=0; i<m; i++){
            st.insert(b[i]);
        }
        
        return st.size();
    }
    
    int doIntersection(int a[], int n, int b[], int m) {
    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0, ans = 0;

    while (i <= j) {
        if (a[i] == b[j]) {
            ans++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return ans;
}

};
