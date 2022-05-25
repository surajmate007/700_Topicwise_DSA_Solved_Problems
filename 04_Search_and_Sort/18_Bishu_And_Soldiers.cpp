// This code is written on hackerearth platform.
// We have to write everything from taking the inputs and printing the outputs.


#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pb push_back

#define vi vector<int>

#define vll vector<ll>

#define vs vector<string>

#define vc vector<char>

#define xag ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



 

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int p;
	int q;cin>>q;

	while(q--){
		int cs=0;
		cin>>p;
		int x=upper_bound(a,a+n,p)-a;
		for(int i=0;i<x;i++){
			cs+=a[i];
		}
		cout<<x<<" "<<cs<<endl;
	}

	return 0;

}
