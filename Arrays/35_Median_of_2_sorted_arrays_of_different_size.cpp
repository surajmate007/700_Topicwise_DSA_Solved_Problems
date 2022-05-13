// first merge two arrays without using extra space then find the mid of two arrays and then based on total size (even or odd) find the median.

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
		   if(mid%2 == 1){
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
