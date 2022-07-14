//Recursive:

 public int lcs(int[] A, int[] B, int m, int n, int res) {
        if (m == -1 || n == -1) {
            return res;
        }
        if (A[m] == B[n]) {
            res = lcs(A, B, m - 1, n - 1, res + 1);
        }
        return max(res, max(lcs(A, B, m, n - 1, 0), lcs(A, B, m - 1, n, 0)));
    }

    public int longestCommonSubString(int[] A, int[] B) {
        return lcs(A, B, A.length - 1, B.length - 1, 0);
    }


// Tabulation:


