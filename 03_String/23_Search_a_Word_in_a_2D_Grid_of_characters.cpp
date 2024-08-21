// This problem is similar to problem solved on leetcode but the difference is onn leetcode we can search in any direction hence the zigzag string 
// was possible but in this problem once we finalised the direction we cant change the direction afterwards. Hence after choosing any of given 8 
// directions then we cant change the direction and keep on searching for the next character in the same direction.
// Here we need to return a 2d array whose indexes represents the start indexes of the word in the grid.

// This solution worked:
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void getAns(vector<vector<char>>& grid, string& word, int len, int sx, int sy, int idx, int i, int j, int n, int m, int dx, int dy){
        if(idx == len){
            if(ans.empty()) ans.push_back({sx, sy});
            else if(ans.back()[0] != sx or ans.back()[1] != sy) ans.push_back({sx, sy});
            return;
        }
        if(i<0 or i>=n or j<0 or j>=m) return;
        
        if(grid[i][j] == word[idx]){
            char ch = grid[i][j]; grid[i][j] = '0';
            getAns(grid, word, len, sx, sy, idx+1, i+dx, j+dy, n, m, dx, dy);
            grid[i][j] = ch;
        }
    }
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size(); int m = grid[0].size(); int len = word.length();
	    ans.clear();
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == word[0]){
	                getAns(grid, word, len, i, j, 0, i, j, n, m, 0, 1);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, 1, 0);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, 0, -1);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, -1, 0);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, 1, 1);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, 1, -1);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, -1, 1);
    	            getAns(grid, word, len, i, j, 0, i, j, n, m, -1, -1);
	            }
	        }
	    }
	    
	    return ans;
	}
};




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
