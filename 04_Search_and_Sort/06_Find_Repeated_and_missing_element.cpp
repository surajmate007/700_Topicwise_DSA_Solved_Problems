/*
    using count array
    TC: O(N)
    SC: O(N)
*/
int* findTwoElement(int* arr, int n) {
        // code here
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0;i < n;i++) {
        cnt[arr[i]]++;
    }
    int* ans = new int[2];
    for (int i = 1;i <= n;i++) {
        if (cnt[i] == 0) ans[1] = i;
        if (cnt[i] == 2) ans[0] = i;
    }

    return ans;
}


/*
    Use elements as Index and mark the visited places
    TC: O(N)
    SC: O(1)
*/

// we are alternatng the sign of the element present at the index of the element in an array.
// hence for all those elements which appeared only one time the nu,ber s become negative in array but for all those which are repeated 2 times the number 
// becomes +ve at that index.

int* findTwoElement(int* arr, int n) {
    int* ans = new int[2], i;

    // here we will keep alternating sign of the place to know which repeated.
    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            // here prev. some no. made negative hence this no. is repeating.
            ans[0] = abs(arr[i]);
    }
    for (i = 0; i < n; i++) {
        // if it positive means none of the element was able to alternate sign.
        // hence that place is the ans.
        if (arr[i] > 0) ans[1] = i + 1;
    }
    return ans;
}
