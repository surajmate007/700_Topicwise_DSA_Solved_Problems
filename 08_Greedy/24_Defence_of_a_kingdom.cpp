// This code is very simple. We are first sorting the x and y cordinates by storing them into seoerate arrays.
// After sorting we are finding the max difference between consequent x co-ordinates and consequent y co-ordinates.
// After finding the max difference we are taking product of this max difference which will give us the max area in between them.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
		int w, h, n;
		cin>>w>>h>>n;
		vector<int> x; vector<int> y;
		x.push_back(0); y.push_back(0);
		for(int i=0; i<n; i++){
			int p; int q;
			cin>>p>>q;
			x.push_back(p);
			y.push_back(q);
		}
		x.push_back(w+1); y.push_back(h+1);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		
		int maxx = 0; int maxy = 0;
		
		for(int i=0; i<x.size()-1; i++){
			maxx = max(maxx, x[i+1]-x[i]-1);
			maxy = max(maxy, y[i+1]-y[i]-1);
		}
		
		cout<<maxx * maxy<<endl;
	}
	return 0;
}
