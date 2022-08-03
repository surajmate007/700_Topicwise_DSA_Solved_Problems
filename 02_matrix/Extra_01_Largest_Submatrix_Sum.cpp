#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

long long getAns(vector<int> vec, int n){
    
    long long osum = vec[0], csum = vec[0];
    
    for(int i=1; i<n; i++){
        if(osum < 0){
            osum = 0;
        }
        
        osum += vec[i];
        csum = max(csum, osum);
    }
    
    return csum;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int> (m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int a; cin>>a;
                arr[i][j] = a;
            }
        }
        
        long long ans = LONG_LONG_MIN;
        
        int k=0;
        while(k<n){
            vector<int> vec(m, 0);
            for(int i=k; i<n; i++){
                for(int j=0; j<m; j++){
                    vec[j] += arr[i][j];
                }
                ans = max(ans, getAns(vec, m));
            }
            k++;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}

