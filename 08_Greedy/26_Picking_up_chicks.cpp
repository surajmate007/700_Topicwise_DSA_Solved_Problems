// Very easy and intuitive solution

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int c; cin>>c; int j=1;
	while(j != c+1){
		int n, k, b, t;
		cin>>n>>k>>b>>t;
		int d[n]; int v[n];
		for(int i=0; i<n; i++){
			cin>>d[i];
		}
		
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		
		int possible = 0; int swaps = 0; int not_possible = 0;
		
		for(int i=n-1; i>=0; i--){
			int dist_needed = b - d[i];
			int dist_possible = v[i] * t;
			
			if(dist_needed <= dist_possible){
				possible ++;
				if(not_possible > 0){
					swaps += not_possible;
				}
			}
			
			else{
				not_possible++;
			}
			
			if(possible >= k){
				break;
			}
		}
		
		if(possible >= k){
			cout<<"Case #"<<j<<": "<<swaps<<endl;
		}
		else{
			cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
		}
		
		j++;
	}
	return 0;
}
