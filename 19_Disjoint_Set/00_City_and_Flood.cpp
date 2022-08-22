// Very easy problem approach:
// Problem Link : https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> parent, size;

void make(int v){
	parent[v] = v;
	size[v] = 1;
}

int find(int v){
	if(parent[v] == v){
		return v;
	}
	return parent[v] = find(parent[v]);
}

void Union(int a, int b){
	a = find(a);
	b = find(b);

	if(a != b){
		if(size[a] < size[b]){
			swap(a, b);
		}
		parent[b] = a;
		size[a] += size[b];
	}
}

int main() {
	int n, k; 
	cin>>n>>k;

	parent.resize(n+1, 0);
	size.resize(n+1, 0);

	for(int i=1; i<=n; i++){
		make(i);
	}

	for(int i=0; i<k; i++){
		int a, b;
		cin>>a>>b;
		Union(a, b);
	}

	long long ans = 0;
	for(int i=1; i<=n; i++){
		if(find(i) == i){
			ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}
