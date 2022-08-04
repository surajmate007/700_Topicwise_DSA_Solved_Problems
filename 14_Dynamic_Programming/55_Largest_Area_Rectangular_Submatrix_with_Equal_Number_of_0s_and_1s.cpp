// Here the approach is simple we are first replacing all the 0 is the matrix with -1 then we are trying to find the largest area submatrix with sum 0.


#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int> vec, int n, int hi, int lo){
    int area = 0;
    unordered_map<int, int> mp;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += vec[i];
        if(sum == 0){
            int ar = (hi-lo+1) * (i+1);
            area = max(area, ar);
        }
        else if(mp.find(sum) != mp.end()){
            int ar = (hi-lo+1) * (i-mp[sum]);
            area = max(area, ar);
        }
        else{
            mp[sum] = i;
        }
    }

    return area;
}

int maximumArea(vector<vector<int>>& mat, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0){
                mat[i][j] = -1;
            }
        }
    }
    
    int ans = 0;
    int k = 0;
    
    while(k < n){
        vector<int> vec(m, 0);
        for(int i=k; i<n; i++){
            for(int j=0; j<m; j++){
                vec[j] += mat[i][j];
            }
            ans = max(ans, getAns(vec, m, i, k));   
        }
        k++;
    }
    return ans;
}

