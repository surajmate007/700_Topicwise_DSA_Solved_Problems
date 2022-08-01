#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void build(int ind, int lo, int hi, vector<int>& arr, vector<int>& seg, int level){
    if(lo == hi){
        seg[ind] = arr[lo];
        return;
    }
    
    int mid = (lo + hi)/2;
    build(2*ind+1, lo, mid, arr, seg, 1-level);
    build(2*ind+2, mid+1, hi, arr, seg, 1-level);
    
    if(level == 1){
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
}

void update(int ind, int lo, int hi, int i, int val, vector<int>& seg, int level){
    if(lo == hi){
        seg[ind] = val;
        return;
    }
    
    int mid = (lo + hi)/2;
    if(i <= mid){
        update(2*ind+1, lo, mid, i, val, seg, 1-level);
    }
    else{
        update(2*ind+2, mid+1, hi, i, val, seg, 1-level);
    }
    
    if(level == 1){
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    }
    else{
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
}

int main() {
	int n, m;
	cin>>n>>m;
	int size = n<<1;
	vector<int> arr;
	vector<int> seg(4*size);
	
	while(size--){
	    int a; cin>>a;
	    arr.push_back(a);
	}
	
	if(n%2 == 0){
	    build(0, 0, arr.size()-1, arr, seg, 0);
	}
	else{
	    build(0, 0, arr.size()-1, arr, seg, 1);
	}
	
	while(m--){
	    int p, b;
	    cin>>p>>b;
	    
	    if(n%2 == 0){
	        update(0, 0, arr.size()-1, p-1, b, seg, 0);
	    }
	    else{
	        update(0, 0, arr.size()-1, p-1, b, seg, 1);
	    }
	    
	    cout<<seg[0]<<endl;
	}

	return 0;
}
