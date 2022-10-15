// simple 2d matrix sum algorithm is used.
// find all possible 2d matrix sums and then keep on updating the answer variable based on the size of the square. 

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int tar) {
        int n = mat.size(); int m = mat[0].size();
        int ans = 0; int p = 0;

        while(p<n){
            vector<int> dp(m, 0);
            for(int i=p; i<n; i++){
                for(int j=0; j<m; j++){
                    dp[j] += mat[i][j];
                }
                vector<int> ndp = dp;
                for(int j=1; j<m; j++){
                    ndp[j] += ndp[j-1];
                }

                if(i-p<m and ndp[i-p] <= tar){
                    ans = max(ans, i-p+1);
                    continue;
                }
                int x = i-p+1; int y = 0;
                while(x<m){
                    if(ndp[x] - ndp[y] <= tar){
                        ans = max(ans, i-p+1);
                        break;
                    }
                    x++; y++;
                }
            }
            p++;
        }
        return ans;
    }
};
