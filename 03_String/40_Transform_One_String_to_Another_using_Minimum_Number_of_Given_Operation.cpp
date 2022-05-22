// This is the simple solution given on gfg:

int minOps(string& A, string& B){
    int m = A.length(), n = B.length();
 
    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in A
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // subtract count for every character in B
    for (int i = 0; i < n; i++)
        count[B[i]]--;
    // Check if all counts become 0
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
 
    // This part calculates the number of operations
    // required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j]) {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0) {
            i--;
            j--;
        }
    }
    return res;
}
