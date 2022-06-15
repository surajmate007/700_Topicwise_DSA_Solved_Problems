// Solved using backtracking.

// Problem Link : https://www.codingninjas.com/codestudio/problems/longest-route_1170525?leftPanelTab=0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void getAns(int n, int m, vector<vector<int>>& a, int sx, int sy, int dx, int dy, int d, int& ans){
    if(sx == dx and sy == dy){
        ans = max(ans, d);
        return;
    }
    
    a[sx][sy] = 0;
    if(sx-1>=0 and a[sx-1][sy]==1){
        getAns(n, m, a, sx-1, sy, dx, dy, d+1, ans);
    }
    if(sy-1>=0 and a[sx][sy-1]==1){
        getAns(n, m, a, sx, sy-1, dx, dy, d+1, ans);
    }
    if(sx+1<n and a[sx+1][sy]==1){
        getAns(n, m, a, sx+1, sy, dx, dy, d+1, ans);
    }
    if(sy+1<m and a[sx][sy+1]==1){
        getAns(n, m, a, sx, sy+1, dx, dy, d+1, ans);
    }
    a[sx][sy] = 1;
}


int longestPath(int n, int m, vector<vector<int>> &mat, int sx, int sy, int dx, int dy) {
    if(mat[sx][sy] == 0 or mat[dx][dy] == 0){
        return -1;
    }
    
    int ans = -1;
	getAns(n, m, mat, sx, sy, dx, dy, 0, ans);
    
    return ans;
}
