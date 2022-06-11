// same problem as 17

long long int maxSum(int arr[], int n){
    sort(arr, arr+n);
    int i=0; int j=n-1;

    vector<int> vec;
    
    while(i <= j){
        vec.push_back(arr[i]);
        vec.push_back(arr[j]);
        i++; j--;
    }
  
    long long int ans = 0;
    for(int i=0; i<n-1; i++){
        ans += abs(vec[i] - vec[i+1]);
    }
    ans += abs(vec[0] - vec[n-1]);
    
    return ans;
}
