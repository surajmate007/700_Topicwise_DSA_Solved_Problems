// Recursive Code:


#include<bits/stdc++.h>

int getAns(vector<vector<int>> &grid, int n, int m, int row, int j1, int j2){
    if(j1<0 or j2<0 or j1>=m or j2>=m or row >= n){
        return -1e9;
    }
    
    if(row == n-1){
        if(j1 == j2){
            return grid[row][j1];
        }
        else{
            return grid[row][j1] + grid[row][j2];
        }
    }
    
    int alice = 0; int bob = 0;
    
    if(j1 == j2){
        alice = grid[row][j1]; 
    }
    else{
        alice = grid[row][j1];
        bob = grid[row][j2];
    }
    
    int temp1 = 0;
    for(int k=j1-1; k<=j1+1; k++){
        int temp2 = 0;
        for(int l=j2-1; l<=j2+1; l++){
            temp2 = max(temp2, {getAns(grid, n, m, row+1, k, l)});
        }
        temp1 = max(temp1, temp2);
    }
    
    return temp1 + alice + bob;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    return getAns(grid, r, c, 0, 0, c-1);
}


// Memoised:


#include<bits/stdc++.h>

int getAns(vector<vector<int>> &grid, int n, int m, int row, int j1, int j2, vector<vector<vector<int>>>& dp){
    if(j1<0 or j2<0 or j1>=m or j2>=m or row >= n){
        return -1e9;
    }
    
    if(row == n-1){
        if(j1 == j2){
            return grid[row][j1];
        }
        else{
            return grid[row][j1] + grid[row][j2];
        }
    }
    
    if(dp[row][j1][j2] != -1){
        return dp[row][j1][j2];
    }
    
    int alice = 0; int bob = 0;
    
    if(j1 == j2){
        alice = grid[row][j1]; 
    }
    else{
        alice = grid[row][j1];
        bob = grid[row][j2];
    }
    
    int temp1 = 0;
    for(int k=j1-1; k<=j1+1; k++){
        int temp2 = 0;
        for(int l=j2-1; l<=j2+1; l++){
            temp2 = max(temp2, {getAns(grid, n, m, row+1, k, l, dp)});
        }
        temp1 = max(temp1, temp2);
    }
    
    return dp[row][j1][j2] = temp1 + alice + bob;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return getAns(grid, r, c, 0, 0, c-1, dp);
}

