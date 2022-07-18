// Important problem.

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        int count = 0;
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){
                unordered_map<int, int> mp;
                mp[0] = 1; int sum = 0;
                
                for(int r=0; r<n; r++){
                    sum += matrix[r][c2] - (c1>0 ? matrix[r][c1-1] : 0);
                    count += mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        
        return count;
    }
};
