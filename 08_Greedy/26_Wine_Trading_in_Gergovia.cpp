// This is the sliding window technique to solve this problem.

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	while(n != 0){
    	int a[n];
    	for(int i=0; i<n; i++){
    		cin>>a[i];
    	}
    	
    	int i=0; int j=0; long long ans = 0;
    	while(i<n and j<n){
    	    
    		if(a[j] >= 0){ j++; continue;}
    		if(a[i] <= 0){ i++; continue;}
    		
    		if(abs(a[i]) < abs(a[j])){
    			ans += (abs(a[i]) * (abs(j-i)));
    			a[j] += a[i]; a[i] = 0;
    			i++;
    			continue;
    		}
    		
    		else if(abs(a[j]) < abs(a[i])){
    			ans += (abs(a[j]) * (abs(j-i)));
    			a[i] += a[j]; a[j] = 0;
    			j++;
    			continue;
    		}
    		
    		else{
    			ans += (abs(a[j]) * abs(j-i));
    			a[i] = 0; a[j] = 0;
    			i++; j++;
    		}
    	}
    	cout<<ans<<endl;
    	
    	cin>>n;
	}
	
	return 0;
}
