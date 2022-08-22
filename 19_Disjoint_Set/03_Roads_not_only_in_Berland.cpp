// Simple solution using disjoint set.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> parent, Size;
vector<vector<int>> unec;

void make(int v){
    parent[v] = v;
    Size[v] = 1;
}

int find(int v){
    if(parent[v] == v){
        return v;
    }
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
    int p = a; int q = b;
    a = find(a); b = find(b);
    
    if(a != b){
        if(Size[b] > Size[a]){
            swap(a, b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
    else{
        unec.push_back({p, q});
    }
}

int main() {
	int n; cin>>n;
	
	parent.resize(n+1);
	Size.resize(n+1);
    unec.resize(0);
	
	for(int i=1; i<=n; i++){
	    make(i);
	}
	
	for(int i=0; i<n-1; i++){
	    int a, b;
	    cin>>a>>b;
	    Union(a, b);
	}
	vector<int> needed;
	    
	for(int i=1; i<=n; i++){
	    if(find(i) == i){
	        needed.push_back(i);
	    }
	}
	    
	vector<vector<int>> ans;
	int k = needed.size();
	
	for(int i=0; i<k-1; i++){
	    int a = needed[i]; int b = needed[i+1];
	    int p = unec[i][0]; int q = unec[i][1];
	    ans.push_back({p, q, a, b});
	}
	
	cout<<k-1<<endl;
	for(int i=0; i<k-1; i++){
	    cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
	}
	   
	return 0;
}
