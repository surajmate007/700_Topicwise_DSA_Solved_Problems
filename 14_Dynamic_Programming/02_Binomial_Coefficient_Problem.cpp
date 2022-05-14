// we are using the m\athematical fact for solving this problem using dp:
// nCr = (n-1)Cr + (n-1)C(r-1)

// Recursive Approach:

int recur(int n, int r) {
    // base condition
    if (r == 0 || r == n) return 1;
    if (n < r) return 0;

    return recur(n - 1, r - 1) + recur(n - 1, r);
}
int nCr(int n, int r) {
    return recur(n, r);
}

// Memoized Approach:

long long memo[1001][1001];
const long long mod = 1e9 + 7;
int recur(int n, int r) {
    // base condition
    if (r == 0 || r == n) return 1;
    if (n < r) return 0;
    if (memo[n][r] != -1) return memo[n][r];

    return memo[n][r] = ((recur(n - 1, r - 1) % mod) + (recur(n - 1, r) % mod) % mod);
}
int nCr(int n, int r) {
    memset(memo, -1, sizeof(memo));
    return recur(n, r) % mod;
}

// Top-Down Approach:

const long long mod = 1e9 + 7;
int memo[1001][1001];
int nCr(int n, int r) {
    if (n < r) return 0;

    // base condition

    for (int j = 0;j < r + 1;j++) {
        memo[0][j] = 0;
    }
    for (int i = 0;i < n + 1;i++) {
        memo[i][0] = 1;
    }

    for (int i = 1;i < n + 1;i++) {
        for (int j = 1;j <= min(i, r);j++) {
            memo[i][j] = (memo[i - 1][j - 1] % mod + memo[i - 1][j] % mod) % mod;
        }
    }
    return memo[n][r] % mod;
}
