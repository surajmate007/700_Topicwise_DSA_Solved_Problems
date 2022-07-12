// Using recursive approach but giving TLE:
// The logic is first forming all the subsequences of length 3 and checking their sum is less than given value or not.
// if satisfying all the conditions then incrementing the number of found triplets.

int gettrips(long long arr[], int n, int idx, long long sum, long long adn, vector<long long>& ds){
	    int found = 0;
	    if(ds.size() == 3 and adn < sum){
	        return 1;
	    }
	    if(idx >= n){
	        return 0;
	    }
	    
	    ds.push_back(arr[idx]);
	    adn += arr[idx];
	    found += gettrips(arr, n, idx+1, sum, adn, ds);
	    ds.pop_back();
	    adn -= arr[idx];
	    found += gettrips(arr, n, idx+1, sum, adn, ds);
	    
	    return found;
	}
	
	long long countTriplets(long long arr[], int n, long long sum){
	    vector<long long> ds;
	    long long adn = 0;
	    
	    return gettrips(arr, n, 0, sum, 0, ds);
	    
	}


// Simple solution.
// first sort the array and then using one for loop to fix one element and then using 2 pointer approach to find the remaining 2 elements.

long long countTriplets(long long arr[], int n, long long sum){
	sort(arr , arr+n);
        long long cnt=0;
        for(int i=0 ; i<n-2 ; i++){
            int j=i+1;
            int k=n-1;
            while(j < k){
                long long s = arr[i] + arr[j] + arr[k];
          
                if(s < sum){
                    cnt+=(k-j);
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        
        return cnt;
	}

