// Easy solution of backtracking

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void getAns(vector<vector<int>> a, int m, int n, int i, int j, vector<int>ds, vector<vector<int>>& ans){
    
    if(i<0 or j<0 or i>=m or j>=n){
        return;
    }
    
    ds.push_back(a[i][j]);
        
    if(i==m-1 and j==n-1){
        ans.push_back(ds);
        return;
    }
    
    getAns(a, m, n, i, j+1, ds, ans);
    getAns(a, m, n, i+1, j, ds, ans);
}


vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n){
    vector<int> ds;
    vector<vector<int>> ans;
    
    getAns(mat, m, n, 0, 0, ds, ans);
    
    return ans;
}

