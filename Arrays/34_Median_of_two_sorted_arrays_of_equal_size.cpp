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
