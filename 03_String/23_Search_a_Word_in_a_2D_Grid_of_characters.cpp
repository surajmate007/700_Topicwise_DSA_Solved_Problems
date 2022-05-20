// This problem is similar to problem solved on leetcode but the difference is onn leetcode we can search in any direction hence the zigzag string 
// was possible but in this problem once we finalised the direction we cant change the direction afterwards. Hence after choosing any of given 8 
// directions then we cant change the direction and keep on searching for the next character in the same direction.

// solution giving proper results for every testcase but gfg saying it wrong.

void newFun(vector<vector<int>>& ans, int n, int m, int i, int j, int idx, vector<vector<char>>& grid, string word, int dir, int istart, int jstart){
        
        if(i>=0 and i<n and j>=0 and j<m and word[idx] == grid[i][j]){
            char temp = word[idx];
            grid[i][j] = '0';
            idx++;
            if(idx == word.length()){
                vector<int> vec;
                vec.push_back(istart);
                vec.push_back(jstart);
                ans.push_back(vec);
                return;
            }
            if(idx == 1){
                newFun(ans, n, m, i, j+1, idx, grid, word, 0, i, j);
                newFun(ans, n, m, i+1, j, idx, grid, word, 1, i, j);
                newFun(ans, n, m, i, j-1, idx, grid, word, 2, i, j);
                newFun(ans, n, m, i-1, j, idx, grid, word, 3, i, j);
                newFun(ans, n, m, i+1, j+1, idx, grid, word, 4, i, j);
                newFun(ans, n, m, i+1, j-1, idx, grid, word, 5, i, j);
                newFun(ans, n, m, i-1, j-1, idx, grid, word, 6, i, j);
                newFun(ans, n, m, i-1, j+1, idx, grid, word, 7, i, j);
                
            }
            else{
                if(dir == 0){
                    newFun(ans, n, m, i, j+1, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 1){
                    newFun(ans, n, m, i+1, j, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 2){
                    newFun(ans, n, m, i, j-1, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 3){
                    newFun(ans, n, m, i-1, j, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 4){
                    newFun(ans, n, m, i+1, j+1, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 5){
                    newFun(ans, n, m, i+1, j-1, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 6){
                    newFun(ans, n, m, i-1, j-1, idx, grid, word, dir, istart, jstart);
                }
                else if(dir == 7){
                    newFun(ans, n, m, i-1, j+1, idx, grid, word, dir, istart, jstart);
                }
            }
            grid[i][j] = temp;
        }
        return;
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(); int m = grid[0].size();
	    vector<vector<int>> ans;
	   
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            newFun(ans, n, m, i, j, 0, grid, word, 10, 0, 0);
	        }
	    }
	    return ans;
	}
