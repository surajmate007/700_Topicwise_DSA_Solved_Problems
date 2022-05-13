// medain is nothing but the middle element when the array is sorted and size is odd. while it is mean of two middle elements when the array is 
// sorted and the size is even.

int find_median(vector<int> v){
		   sort(v.begin(), v.end());
		   int n = v.size();
		   if(n%2 == 1){
		       return v[v.size()/2];
		   }
		   else{
		       n = n/2;
		       return (v[n]+v[n-1])/2;
		   }
		   
}

// original answer for this problem

int find_median(vector<int> a, vector<int> b){
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
		   return (a[n-1] + b[0])/2;
}
