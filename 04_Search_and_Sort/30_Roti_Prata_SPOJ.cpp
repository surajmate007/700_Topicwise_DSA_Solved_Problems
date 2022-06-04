#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool minTime(int rank[], int P, int K, int mid){
	int sum = 0; int p = 1; int i = 1; int idx = 0; int ans = INT_MIN;
// 	cout<<"mid is : "<<mid<<endl;
	while(p != P+1){
		sum += (rank[i-1] * (p-idx));
		
		if(sum > mid){
			idx = p-1;
			i++;
			sum = rank[i-1];
		}
		if(i > K or rank[i-1]>mid){
			return false;
		}
// 		cout<<"Sum is : "<<sum<<endl;
		ans = max(ans, sum);
		p++;
	}
// 	cout<<"return  value : "<<ans<<endl;
	return true;
}


int getAns(int rank[], int P, int K, int lo, int hi){
	int fans = INT_MAX;
	while(lo <= hi){
		int mid = (lo + hi)/2;
		int mtime = minTime(rank, P, K, mid);
		if(mtime == false){
			lo = mid + 1;
		}
		else{
			fans = min(fans, mtime);
			hi = mid - 1;
		}
	}
	return fans;
} 


int main() {
	int T;
	cin>>T;
	while(T){
		int P; int K;
		cin>>P;
		cin>>K;
		int rank[K];
		int hi = INT_MIN;
		for(int i=0; i<K; i++){
			cin>>rank[i];
			hi = max(hi, rank[i]);
		}
		int fn = P*(P+1)/2;
		hi = fn * hi;
		
		int ans = getAns(rank, P, K, 0, hi);
		cout<<ans<<endl;
		
		T--;
	}
	return 0;
}
