// This is the most important use case of binary learch where we are finding the nth root of any givrn number using binary search technique.

#include<bits/stdc++.h>

double getPow(double n, int m){
    double ans = 1.0;
    for(int i=1; i<=m; i++){
        ans = ans * n;
    }
    return ans;
}

double findNthRootOfM(int n, int m) {
	double lo = 1.0; double hi = m; double lim = 1e-8;
    while((hi - lo) > lim){
        double mid = (hi+lo)/2.0;
        
        if(getPow(mid, n) < m){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    
    return lo;
}
