// We are using the sam recursive approach that is taught in gfg article here direction does not matter hence we can go for searching in any random
// direction:

class Solution {
public:
    int serach(vector<vector<char>>& board, string word, int n, int m, int i, int j, int idx){
        int found = 0;
        if(i>=0 and i<n and j>=0 and j<m and board[i][j]==word[idx]){
            char temp = word[idx];
            idx++;
            board[i][j] = '0';
            if(idx == word.size()){
                return 1;
            }
            else{
                found += serach(board, word, n, m, i, j+1, idx);
                found += serach(board, word, n, m, i+1, j, idx);
                found += serach(board, word, n, m, i, j-1, idx);
                found += serach(board, word, n, m, i-1, j, idx);
            }
            board[i][j] = temp;
        }
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); int m = board[0].size(); int found = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                found += serach(board, word, n, m, i, j, 0);
            }
        }
        if(found > 0){
            return true;
        }
        return false;
    }
};
