// Solved by me. Similar question is already solved in string section.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int maxf = 0; int n = s.length();
	    unordered_map<char, int> mp;
	    for(int i=0; i<n; i++){
	        mp[s[i]]++;
	        maxf = max(maxf, mp[s[i]]);
	    }
	    
	    if((n - maxf) >= (maxf-1)){
	        cout<<"1"<<endl;
	    }
	    else{
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
