// here dp[i][j] stores the max size square that can be formed upto the index i and j in the given matrix.
// we are first sillimg all the row = 0 and col = 0 entries in our dp matrix.
// then for every index we are checking the min of top, left and right and then we are finding the value of given cell by adding 1 to this minimum value.

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int ans = 0;
        
        int dp[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 or j==0){
                    dp[i][j] = mat[i][j];
                }
                else{
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(mat[i][j] == 1){
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                else{
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
