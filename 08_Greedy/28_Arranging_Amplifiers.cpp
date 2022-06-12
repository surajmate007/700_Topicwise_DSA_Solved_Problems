// The simple mathematical conclusion we can derive is just 2 3 is an exception where the value of 2^3 > 3^2 but in all other cases
// The value is high when thew term at base is larger initially. Hence we are sorting the array in reverse order and also we are handling 1 values 
// seperately.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n]; int ones = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i] == 1){
                ones++;
            }
        }
        sort(a, a+n, greater<int>());
        
        for(int i=0; i<ones; i++){
            cout<<"1 ";
        }
        
        if(n-ones==2 and a[0]==3 and a[1]==2){
            cout<<"2 3";
        }
        
        else{
            for(int i=0; i<n-ones; i++){
                cout<<a[i]<<" ";
            }
        }
        
        cout<<endl;
    }
	return 0;
}
