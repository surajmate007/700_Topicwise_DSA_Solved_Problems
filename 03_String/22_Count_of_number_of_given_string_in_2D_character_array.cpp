// utility function to search
// complete string from any
// given index of 2d char array
int internalSearch(string word, int row, int col, vector<vector<char>>& gird, int row_max, int col_max, int idx){
    int found = 0;
 
    if (row >= 0 && row <= row_max && col >= 0 && col <= col_max && word[idx] == grid[row][col]){
        char temp = word[idx];
        idx += 1;
        gird[row][col] = 0;
        if(idx == word.size()){
          found = 1;
        }
        else{
            // through Backtrack searching
            // in every directions
            found += internalSearch(word, row, col + 1, gird, row_max, col_max, idx);
            found += internalSearch(word, row, col - 1, gird, row_max, col_max, idx);
            found += internalSearch(word, row + 1, col, gird, row_max, col_max, idx);
            found += internalSearch(word, row - 1, col, gird, row_max, col_max, idx);
        }
        grid[row][col] = temp;
    }
    return found;
}

int searchString(string word, vector<vector<char>>& gird){
    int found = 0;
    int row_count = grid.size();
    int col_count = grid[0].size();
    int r, c;
    for (r = 0; r < row_count; r++){
        for (c = 0; c < col_count; c++){
            found += internalSearch(word, r, c, grid, row_count - 1, col_count - 1, 0);
        }
    }
    return found;
}
