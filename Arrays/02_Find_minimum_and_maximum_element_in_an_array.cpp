pair<long long, long long> getMinMax(long long a[], int n) {
    long long min = LONG_MAX;
    long long max = LONG_MIN;
    for(int i=0; i<n; i++){
        if(a[i] < min){
            min = a[i];
        }
        
        if(a[i] > max){
            max = a[i];
        }
    }
   
    pair<long long, long long> pr = {min, max};
    return pr;
}
