
// Most efficient solution taking only o(log(min(n, m)) Complexity:

#include<bits/stdc++.h>

double median(vector<int> a, vector<int> b){
    int n = a.size(); int m = b.size();
    if(n>m){
        return median(b, a);
    }
    
    int lo = 0; int hi = n; int med = (m+n+1)/2;
    while(lo <= hi){
        int cut1 = (lo+hi)>>1;
        int cut2 = med - cut1;
        int l1 = (cut1==0)? INT_MIN : a[cut1-1];
        int l2 = (cut2==0)? INT_MIN : b[cut2-1];
        int r1 = (cut1==n)? INT_MAX : a[cut1];
        int r2 = (cut2==m)? INT_MAX : b[cut2];
        
        if(l1<=r2 and l2<=r1){
            if((m+n)%2==0){
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            return max(l1, l2);
        }
        else if(l1 > r2){
            hi = cut1-1;
        }
        else{
            lo = cut1+1;
        }
    }
    
    return 0.0;
}


// first merge two arrays without using extra space then find the mid of two arrays and then based on total size (even or odd) find the median.
// this solution takes O(m+n) complexity.

int find_median_different_sizes(vector<int> a, vector<int> b){
		   int n = a.size(); int m = b.size();
		   int i=0; int j=0; int k = n-1
		   
		   while(i<=k and j<m){
		       if(a[i] < b[j]){
		           i++;
		       }
		       else{
		           swap(a[k], b[j]);
		           j++; k--;
		       }
		   }
		   
		   sort(a.begin(), a.end());
		   sort(b.begin(), b.end());
		   
		   int mid = (n+m)/2;
		   if((m+n)%2 == 1){
		       if(n > mid){
		           return a[mid];
		       }
		       else{
		           return b[mid-n];
		       }
		   }
		   else{
		       if(n > mid){
		           return (a[mid] + a[mid-1])/2;
		       }
		       else{
		           return (b[mid-n] + b[mid-n-1])/2;
		       }
		   }
		   
}
