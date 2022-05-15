#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int>& vec){
    int p=0; int q=vec.size()-1;
    while(p <= q){
        swap(vec[p], vec[q]);
        p++;
        q--;
    }
}
 
int main() {
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
	    int N;
	    cin>>N;
	    vector<int>vec(N, 0);
	    for(int i=0; i<N; i++){
	        int p;
	        cin>>p;
	        vec[i] = p;
	    }
	    
	    reverse(vec);
	    
	    for(int i=0; i<N; i++){
	        cout<<vec[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
