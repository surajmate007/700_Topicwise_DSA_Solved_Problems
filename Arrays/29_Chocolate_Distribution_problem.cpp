// we will first sort the array and then find the minimum difference between the number of chocolates given to 2 different studentrs from the sorted array.

long long findMinDiff(vector<long long> a, long long n, long long m){
        long long ans = INT_MAX;
        sort(a.begin(), a.end());
        int i = 0 ; int j = m-1;
        while(j < n){
            ans = min(ans, a[j]-a[i]);
            j++; i++;
        }
        return ans;
    }   
