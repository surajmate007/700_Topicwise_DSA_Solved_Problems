// Recursive approach:

class Solution{
public:
    int getmcm(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        int mn = INT_MAX;
        for(int k=i; k<j; k++){
            int temp_ans = getmcm(arr, i, k) + getmcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            mn = min(temp_ans, mn);
        }
        return mn;
    }
    int matrixMultiplication(int N, int arr[]){
        return getmcm(arr, 1, N-1);
    }
};

// Memoized Approach:

class Solution{
public:
    int dp[1001][1001];
    
    int getmcm(int arr[], int i, int j){
        if(i>=j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i; k<j; k++){
            int temp_ans = getmcm(arr, i, k) + getmcm(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
            mn = min(temp_ans, mn);
        }
        return dp[i][j] = mn;
    }
    
    int matrixMultiplication(int N, int arr[]){
        memset(dp, -1, sizeof(dp));
        return getmcm(arr, 1, N-1);
    }
};

// Top-Down Approach:
class Solution{
public:
    int getmcm(int p[], int n){

        /* For simplicity of the program, one
        extra row and one extra column are
        allocated in dp[][]. 0th row and 0th
        column of dp[][] are not used */
        int dp[n][n];

        int i, j, k, L, q;

        /* m[i, j] = Minimum number of scalar
        multiplications needed to compute the
        matrix A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is p[i-1] x p[i] */

        // cost is zero when multiplying one matrix.
        for (i = 1; i < n; i++)
            m[i][i] = 0;


        for (L = 2; L < n; L++){
            for (i = 1; i < n - L + 1; i++){
                j = i + L - 1;
                m[i][j] = INT_MAX;
                for (k = i; k < j; k++){
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                        m[i][j] = q;
                }
            }
        }
    return m[1][n - 1];
 }
};
