// this is not the original problem:

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> vec;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                vec.push_back(Mat[i][j]);
            }
        }
        
        sort(vec.begin(), vec.end());
        int p=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                Mat[i][j] = vec[p];
                p++;
            }
        }
        
        return Mat;
    }
};
