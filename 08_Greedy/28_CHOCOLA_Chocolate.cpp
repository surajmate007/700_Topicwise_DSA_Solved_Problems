// Similar problem is also solved before in Greedy algorithms.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        int x[m]; int y[n];
        for(int i=0; i<m-1; i++){
            cin>>x[i];
        }
        
        for(int j=0; j<n-1; j++){
            cin>>y[j];
        }
        
        sort(x, x+m-1, greater<int>()); sort(y, y+n-1, greater<int>());
        
        int verti_pieces = 1; int horiz_pieces = 1; int ans = 0;
        int i=0; int j=0;
        
        while(i<m-1 and j<n-1){
            if(x[i] > y[j]){
                ans += (x[i] * verti_pieces);
                horiz_pieces++; i++;
            }
            else{
                ans += (y[j] * horiz_pieces);
                verti_pieces++; j++;
            }
        }
        
        while(i < m-1){
            ans += (x[i] * verti_pieces);
            horiz_pieces++; i++;
        }
        
        while(j < n-1){
            ans += (y[j] * horiz_pieces);
            verti_pieces++; j++;
        }
        
        cout<<ans<<endl;
    }
	return 0;
}
