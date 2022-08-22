// Revise

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> parent, size;
multiset<int> mset;

void merge(int a, int b){
	mset.erase(mset.find(size[a]));
	mset.erase(mset.find(size[b]));
	mset.insert(size[a] + size[b]);
}

void make(int v){
	parent[v] = v;
	size[v] = 1;
	mset.insert(1);
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
		if(size[b] > size[a]){
			swap(a, b);
		}
		parent[b] = a;
		merge(a, b);
		size[a] += size[b];
	}
}

int main() {
	int n, q;
	cin>>n>>q;
	parent.resize(n+1);
	size.resize(n+1);
	mset.clear();

	for(int i=1; i<=n; i++){
		make(i);
	}

	while(q--){
		int a, b;
		cin>>a>>b;
		Union(a, b);

		if(mset.size() == 1){
			cout<<0<<endl;
		}
		else{
			int mn = *(mset.begin());
			int mx = *(--mset.end());
			cout<<mx-mn<<endl;
		}
	}

	return 0;
}
